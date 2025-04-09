import script_tester
import pytest
import subprocess

def test_redirection_ambiguous_error_variable():
    script_tester.test("redirection/test_redirection_error/test_redirection_ambiguous_error_variable.sh",
		expected_stdout = (
            "1\n"
            "1\n"
            "1\n"),
        expected_stderr = (
            "minishell: $A$A: ambiguous redirect\n"
            "minishell: $Bob: ambiguous redirect\n"
            "minishell: $Chris: ambiguous redirect\n"
            ))
@pytest.mark.skip(reason="wildcard部分の一時的な除外")
def test_redirection_ambiguous_error_wildcard():
    script_tester.test("redirection/test_redirection_error/test_redirection_ambiguous_error_wildcard.sh",
		expected_stdout = (
            "1\n"
            "1\n"
            "1\n"),
        expected_stderr = (
            "minishell: *: ambiguous redirect\n"
            "minishell: *: ambiguous redirect\n"
            "minishell: *: ambiguous redirect\n"
            ))
