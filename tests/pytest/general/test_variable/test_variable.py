import script_tester
import pytest
import subprocess

def test_SHLVL_basic():
    base_shlvl = int(subprocess.run(['echo $SHLVL'], shell=True, capture_output=True, text=True).stdout) + 1
    script_tester.test("general/test_variable/test_SHLVL_basic.sh",
    expected_stdout = str(base_shlvl + 1) + "\n",
    expected_stderr = "")

def test_SHLVL_overflow_loop():
    script_tester.test("general/test_variable/test_SHLVL_overflow_loop.sh",
        expected_stdout = "3\n",
        expected_stderr = "")

def test_SHLVL_over_1000():
    script_tester.test("general/test_variable/test_SHLVL_over_1000.sh",
        expected_stdout = (
			"1\n"
			"999\n"),
        expected_stderr = "minishell: warning: shell level (1000) too high, resetting to 1\n")

def test_SHLVL_boundary_value():
    script_tester.test("general/test_variable/test_SHLVL_boundary_value.sh",
        expected_stdout = (
			"1\n"
			"0\n"),
        expected_stderr = (
			"minishell: warning: shell level (2147483647) too high, resetting to 1\n"
			))

def test_SHLVL_undefind():
    script_tester.test("general/test_variable/test_SHLVL_undefind.sh",
        expected_stdout = (
			"1\n"),
        expected_stderr = (
			""
			))

def test_SHLVL_invalid_value():
    script_tester.test("general/test_variable/test_SHLVL_invalid_value.sh",
        expected_stdout = (
			"1\n"),
        expected_stderr = (
			""
			))

def test_HISTCMD_unset():
    script_tester.test("general/test_variable/test_HISTCMD_unset.sh",
        expected_stdout = (
            "3\n"
            "3\n"),
        expected_stderr = "")

def test_MNSH_SUBSHELL_overflow():
    script_tester.test("general/test_variable/test_MNSH_SUBSHELL_overflow.sh",
        expected_stdout = (
            "-2147483648\n"
            "0\n"),
        expected_stderr = "")

def test_MNSH_SUBSHELL_unset():
    script_tester.test("general/test_variable/test_MNSH_SUBSHELL_unset.sh",
        expected_stdout = (
            "\n"
            "3\n"
            "0\n"),
        expected_stderr = "")

def test_MNSH_SUBSHELL_basic():
    script_tester.test("general/test_variable/test_MNSH_SUBSHELL_basic.sh",
        expected_stdout = (
            "2\n"
            "5\n"
            "0\n"),
        expected_stderr = "")
