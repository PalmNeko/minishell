import subprocess
import pytest
import os

def run_script(script_file: str, stdin_input: str = ""):
    """ 指定したスクリプトを実行し、stdout, stderr, returncode を返す """
    assert os.path.isfile(script_file), f"Script file not found: {script_file}"
    result = subprocess.run(
        ["bash", script_file],
        input=stdin_input,
        capture_output=True,
        text=True
    )
    return result.stdout, result.stderr, result.returncode

def test(script_file: str, expected_stdout: str = "", expected_stderr: str = "", expected_status: int = 0, stdin_input: str = ""):
    """ pytest 用のスクリプトテスト関数 """
    stdout, stderr, status = run_script(script_file, stdin_input)
    assert status == expected_status, f"Expected status {expected_status}, but got {status}\nScript: {script_file}"
    assert stdout == expected_stdout, f"Expected stdout:\n{expected_stdout}\nGot:\n{stdout}\n"
    assert stderr == expected_stderr, f"Expected stderr:\n{expected_stderr}\nGot:\n{stderr}\n"
