import script_tester
import pytest
import subprocess

dirname = "expansion/pathname_expansion/"

def test_only():
	result = "aaaa  bbbb  cccc  dddd.sh  eeee.sh\n"
	script_tester.test(dirname + "test_include_only_wildcard.sh",
		expected_stdout = result,
		expected_stderr = ""
	)

def test_include_single():
	result = "dddd.sh  eeee.sh\n"
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
