import script_tester
import pytest
import os

def test_basic():
	result = os.path.expandvars("$PATH") + "\n"
	result2 = os.path.expandvars("$HOME") + "\n"
	script_tester.test("variable_expansion/test_basic.sh",
		expected_stdout = result + result2,
		expected_stderr = ""
	)

def test_assignment():
	result = "simple_value" + "\n"
	result2 = "value  include   space" + "\n"
	result3 = "join double quoted & non_quoted & single quoted" + "\n"
	result4 = "assignment($HOGE=hoge) self three time. hogehogehoge" + "\n"
	script_tester.test("variable_expansion/test_assignment.sh",
		expected_stdout = result + result2 + result3 + result4,
		expected_stderr = ""
	)
	