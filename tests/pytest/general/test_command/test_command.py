import script_tester
import pytest

def test_invalid_option():
    script_tester.test("general/test_command/test_command_not_found.sh",
        expected_stdout = "127\n",
        expected_stderr = (
            "minishell: A: command not found\n"))
