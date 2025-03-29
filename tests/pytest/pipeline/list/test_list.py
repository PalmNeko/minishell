import script_tester
import pytest
import os

dirname = "pipeline/list/"

def test_list_status():
	result = "0\n127\n"
	script_tester.test("pipeline/list/test_list_status.sh",
		expected_stdout = result,
		expected_stderr = "minishell: not_such_command: command not found\n"
    					"minishell: ahog: command not found\n"
	)