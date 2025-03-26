import script_tester
import pytest
import subprocess

def test_create_permission():
    script_tester.test("redirection/test_redirection_file_permission/test_create_permission.sh",
        expected_stdout = "-rw-rw-rw\n",
        expected_stderr = "")

def test_append_permission():
    script_tester.test("redirection/test_redirection_file_permission/test_append_permission.sh",
        expected_stdout = "-rw-rw-rw\n",
        expected_stderr = "")
