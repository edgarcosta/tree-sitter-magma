from html.parser import HTMLParser
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
from unittest import TestCase


ROOT = Path(__file__).resolve().parents[2]


class HighlightLines(HTMLParser):
    def __init__(self):
        super().__init__()
        self.lines = []
        self.active = False
        self.classes = []

    def handle_starttag(self, tag, attrs):
        attrs = dict(attrs)
        if tag == "td" and attrs.get("class") == "line":
            self.active = True
            self.lines.append([])
        elif tag == "span" and self.active:
            self.classes.append(frozenset(attrs.get("class", "").split()))

    def handle_endtag(self, tag):
        if tag == "span" and self.active:
            self.classes.pop()
        elif tag == "td":
            self.active = False

    def handle_data(self, data):
        if self.active:
            classes = frozenset().union(*self.classes)
            self.lines[-1].extend((char, classes) for char in data)


class TestHighlightHTML(TestCase):
    def test_constructor_parameter_roles_in_rendered_html(self):
        cli = ROOT / "node_modules/.bin/tree-sitter"
        if not cli.exists():
            executable = shutil.which("tree-sitter")
            self.assertIsNotNone(executable, "Install the pinned Tree-sitter CLI")
            cli = Path(executable)
        cases = [
            ("sum := func<a, b | a + b>;", "func", ("a", "b")),
            ("swap := proc<~x, ~y | Print(x, y)>;", "proc", ("x", "y")),
            ("optional := func<required : First, Second | required + First + Second>;",
             "func", ("required", "First", "Second")),
            ("mixed := proc<value, ~target : Flag | Print(value, target, Flag)>;",
             "proc", ("value", "target", "Flag")),
        ]
        controls = [
            ("record := rec<fmt | first := a, second := b>;",
             {"rec": "function builtin", "fmt": "variable", "first": "property",
              "second": "property", "a": "variable", "b": "variable"}),
            ("declare attributes Rec: first, second;",
             {"Rec": "type", "first": "property", "second": "property"}),
            ("declare type Outer[Element]: Parent;",
             {"Outer": "type", "Element": "type", "Parent": "type"}),
        ]
        lines = [case[0] for case in cases] + [case[0] for case in controls]
        source = "\n".join(lines) + "\n"
        scratch = ROOT / "_worktrees"
        scratch.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=scratch, prefix="highlight-html-") as directory:
            fixture = Path(directory)
            grammar = fixture / "tree-sitter-magma"
            grammar.mkdir()
            for name in ("src", "queries", "grammar.js", "tree-sitter.json"):
                (grammar / name).symlink_to(ROOT / name, target_is_directory=(ROOT / name).is_dir())
            captures = re.findall(r"@([\w.]+)", (ROOT / "queries/highlights.scm").read_text())
            config = fixture / "config.json"
            config.write_text(json.dumps({
                "parser-directories": [str(fixture)],
                "theme": {name: "#222222" for name in captures if not name.startswith("_")},
            }))
            path = fixture / "constructors.m"
            path.write_text(source)
            env = {**os.environ, "XDG_CACHE_HOME": str(fixture / "cache"),
                   "TREE_SITTER_LIBDIR": str(fixture / "lib"),
                   "XDG_CONFIG_HOME": str(fixture / "config"), "TMPDIR": str(fixture)}
            for arguments in (["parse", "--quiet"],
                              ["highlight", "--html", "--css-classes", "--scope", "source.magma"]):
                result = subprocess.run(
                    [str(cli.resolve()), *arguments, "--config-path", str(config), str(path)],
                    cwd=grammar, env=env, capture_output=True, text=True, timeout=30,
                )
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            rendered = HighlightLines()
            rendered.feed(result.stdout)
            self.assertEqual(len(rendered.lines), len(lines))
            for line, chars in zip(lines, rendered.lines):
                self.assertEqual("".join(char for char, classes in chars).rstrip("\n"), line)

            def check_role(row, start, end, role):
                with self.subTest(row=row + 1, span=(start, end), text=lines[row][start:end]):
                    actual = {classes for char, classes in rendered.lines[row][start:end]}
                    self.assertEqual(actual, {frozenset(role.split())})

            for row, (line, constructor, names) in enumerate(cases):
                start = line.index(constructor)
                check_role(row, start, start + len(constructor), "function builtin")
                for match in re.finditer(r"[A-Za-z_]\w*", line):
                    if match[0] in names:
                        role = "variable parameter" if match.start() < line.index("|") else "variable"
                        check_role(row, match.start(), match.end(), role)
            for row, (line, roles) in enumerate(controls, start=len(cases)):
                for match in re.finditer(r"[A-Za-z_]\w*", line):
                    if match[0] in roles:
                        check_role(row, match.start(), match.end(), roles[match[0]])
