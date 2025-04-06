import script_tester
import pytest
import subprocess

dirname = "expansion/pathname_expansion/"

def test_only():
	result = "aaaa\nbbbb\ncccc\ndddd.sh\neeee.sh\n"
	script_tester.test(dirname + "test_include_only_wildcard.sh",
		expected_stdout = result,
		expected_stderr = ""
	)

def test_include_single():
	result = "\ndddd.sh\neeee.sh\n"
	result2 = "no*match\n"
	script_tester.test(dirname + "test_include_single_wildcard.sh",
		expected_stdout = result + result2,
		expected_stderr = ""
	)

def test_include_nothing():
	result = "nothing_wildcard\n"
	script_tester.test(dirname + "test_include_nothing_wildcard.sh",
		expected_stdout = result,
		expected_stderr = ""
	)

def test_double():
	script_tester.test(dirname + "test_double_wildcard.sh",
		expected_stdout = "",
		expected_stderr = ""
	)
