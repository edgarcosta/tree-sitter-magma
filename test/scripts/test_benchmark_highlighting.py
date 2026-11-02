import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
from unittest import TestCase


ROOT = Path(__file__).resolve().parents[2]


class TestBenchmarkHighlighting(TestCase):
    def test_package_labels_through_directory_alias_and_sibling_include(self):
        cli = ROOT / "node_modules/.bin/tree-sitter"
        if not cli.exists():
            executable = shutil.which("tree-sitter")
            self.assertIsNotNone(executable, "Install the pinned Tree-sitter CLI")
            cli = Path(executable)

        scratch = ROOT / "_worktrees"
        scratch.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(dir=scratch, prefix="benchmark-test-") as directory:
            fixture = Path(directory)
            physical = fixture / "physical"
            sibling = fixture / "sibling"
            physical.mkdir()
            sibling.mkdir()
            (physical / "spec").write_text("tiny.m\n+../sibling/spec\n")
            (physical / "tiny.m").write_text("x := 1;\n")
            (sibling / "spec").write_text("other.m\n")
            (sibling / "other.m").write_text("y := 2;\n")
            linked = fixture / "linked"
            linked.symlink_to(physical, target_is_directory=True)
            output = fixture / "report.json"

            result = subprocess.run(
                [sys.executable, str(ROOT / "scripts/benchmark_highlighting.py"),
                 "--cli", str(cli.resolve()), "--spec", str(linked / "spec"),
                 "--sample", "2", "--output", str(output)],
                cwd=ROOT, capture_output=True, text=True,
                env={**os.environ, "TMPDIR": str(fixture),
                     "XDG_CACHE_HOME": str(fixture / "cache")},
                timeout=120,
            )
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            report = json.loads(output.read_text())
            self.assertEqual(report["package_population"], 2)
            package_cases = {case["file"]: case["status"] for case in report["cases"]
                             if case["file"] in ("tiny.m", "../sibling/other.m")}
            self.assertEqual(package_cases, {"tiny.m": "ok", "../sibling/other.m": "ok"})
