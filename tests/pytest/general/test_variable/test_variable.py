import script_tester
import pytest
import subprocess

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
