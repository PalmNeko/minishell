import script_tester
import pytest
import subprocess

testdir = "builtin/exit/test_exit_basic/"

def	test_move_parent():
	script_tester.test(testdir + "test_exit_no_arg.sh",
        expected_stdout = "",
        expected_stderr = "")
