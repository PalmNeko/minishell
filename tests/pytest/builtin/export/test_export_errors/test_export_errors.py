import script_tester
import pytest

@pytest.mark.skip(reason="デバッグの時用")
def test_invalid_option():
    script_tester.test("builtin/cd/test_errors/export_invalid_option.sh",
        expected_stdout = "2\n",
        expected_stderr = (
            "minishell: export: -a: invalid option\n"
            "export: usage: export [name[=value] ...]\n"))
