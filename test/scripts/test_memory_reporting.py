from contextlib import redirect_stdout
import io
import json
import os
from pathlib import Path
import resource
import runpy
import shutil
import subprocess
import sys
import tempfile
from types import SimpleNamespace
from unittest import TestCase
from unittest.mock import patch


ROOT = Path(__file__).resolve().parents[2]


class TestMemoryReporting(TestCase):
    def run_script(self, script, *arguments):
        output = io.StringIO()
        path = ROOT / "scripts" / script
        with patch.object(sys, "argv", [str(path), *map(str, arguments)]), \
                patch.object(sys, "path", sys.path.copy()), redirect_stdout(output):
            with self.assertRaises(SystemExit) as result:
                runpy.run_path(str(path), run_name="__main__")
        self.assertEqual(result.exception.code, 0, output.getvalue())
        return output.getvalue()

    def test_highlighting_report_uses_decimal_megabytes(self):
        cli = ROOT / "node_modules/.bin/tree-sitter"
        if not cli.exists():
            executable = shutil.which("tree-sitter")
            self.assertIsNotNone(executable, "Install the pinned Tree-sitter CLI")
            cli = Path(executable)
        scratch = ROOT / "_worktrees"
        scratch.mkdir(exist_ok=True)
        real_popen = subprocess.Popen
        readings = [
            ("linux", "Maximum resident set size (kbytes): 100000\n"),
            ("darwin", "102400000 maximum resident set size\n"),
        ]
        for system, measurement in readings:
            with self.subTest(platform=system), tempfile.TemporaryDirectory(dir=scratch) as directory:
                fixture = Path(directory)
                report_path = fixture / "report.json"

                def measured_process(command, *args, **kwargs):
                    if command[0] == "/usr/bin/time":
                        return SimpleNamespace(returncode=0, communicate=lambda timeout: (None, measurement))
                    return real_popen(command, *args, **kwargs)

                with patch.object(sys, "platform", system), \
                        patch("subprocess.Popen", side_effect=measured_process), \
                        patch.object(tempfile, "tempdir", str(fixture)), \
                        patch.dict(os.environ, {"TMPDIR": str(fixture), "XDG_CACHE_HOME": str(fixture / "cache")}):
                    self.run_script("benchmark_highlighting.py", "--cli", cli.resolve(), "--output", report_path)
                report = json.loads(report_path.read_text())
                self.assertTrue(report["cases"])
                self.assertEqual({case["status"] for case in report["cases"]}, {"ok"})
                self.assertEqual({case["peak_rss_mb"] for case in report["cases"]}, {102.4})

    def test_corpus_summary_uses_decimal_megabytes(self):
        import tree_sitter_magma

        scratch = ROOT / "_worktrees"
        scratch.mkdir(exist_ok=True)
        for system, raw_peak in [("linux", 100000), ("darwin", 102400000)]:
            with self.subTest(platform=system), tempfile.TemporaryDirectory(dir=scratch) as directory:
                source = Path(directory) / "tiny.m"
                source.write_text("x := 1;\n")
                values = list(resource.getrusage(resource.RUSAGE_SELF))
                values[2] = raw_peak
                reading = resource.struct_rusage(values)
                with patch.object(sys, "platform", system), \
                        patch("resource.getrusage", return_value=reading):
                    output = self.run_script("parse_corpus.py", source)
                self.assertIn("files: 1  with errors: 0  bytes: 8", output)
                self.assertIn("peak RSS: 102 MB", output)
