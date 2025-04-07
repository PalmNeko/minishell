import script_tester
import pytest
import subprocess

testdir = "builtin/exit/test_exit_errors/"

def	test_exit_overflow():
	script_tester.test(testdir + "test_exit_overflow.sh",
        expected_stdout = "2\n",
        expected_stderr = "minishell: exit: 9223372036854775808: numeric argument required\n")

def	test_numeric_argument_required():
	script_tester.test(testdir + "test_numeric_argument_required.sh",
        expected_stdout = "2\n",
        expected_stderr = "minishell: exit: a: numeric argument required\n")

def	test_exit_too_many_argument():
	script_tester.test(testdir + "test_exit_too_many_argument.sh",
        expected_stdout = "1\n",
        expected_stderr = "minishell: exit: too many arguments\n")
