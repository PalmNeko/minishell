import script_tester
import pytest
import subprocess

def test_invalid_option():
    script_tester.test("general/test_command/test_command_not_found.sh",
        expected_stdout = "127\n",
        expected_stderr = (
            "minishell: A: command not found\n"))

def test_initial_status():
    script_tester.test("general/test_command/test_status.sh",
        expected_stdout = "0\n",
        expected_stderr = (
            ""))

def test_absolute_path():
    result = subprocess.run(['/bin/ls','general/test_command'], capture_output=True, text=True)
    script_tester.test("general/test_command/test_absolute_path.sh",
        expected_stdout = result.stdout,
        expected_stderr = ""
        )

def test_error_will_run_directory():
    script_tester.test("general/test_command/test_error_will_run_directory.sh",
        expected_stdout = "126\n",
        expected_stderr = "minishell: ./: Is a directory\n"
        )

def test_error_permission_denied():
    script_tester.test("general/test_command/test_error_permission_denied.sh",
        expected_stdout = "126\n",
        expected_stderr = "minishell: ./anyfile.out: Permission denied\n"
        )
