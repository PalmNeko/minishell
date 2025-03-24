import script_tester
import pytest

@pytest.mark.skip(reason="デバッグの時用")
def test_no_such_file_or_directory():
    script_tester.test("builtin/cd/test_errors/no_such_file_or_directory.sh",
        expected_stdout = "1\n",
        expected_stderr = "minishell: cd: hogehoge_no_exist_dir: No such file or directory\n")

@pytest.mark.skip(reason="デバッグの時用")
def test_too_many_arguments():
    script_tester.test("builtin/cd/test_errors/too_many_arguments.sh",
        expected_stdout = "1\n",
        expected_stderr = "minishell: cd: too many arguments\n")

@pytest.mark.skip(reason="デバッグの時用")
def test_invalid_option():
    script_tester.test("builtin/cd/test_errors/too_many_arguments.sh",
        expected_stdout = "2\n",
        expected_stderr = "minishell: cd: -A: invalid option\n" "cd: usage: cd [-L|[-P [-e]]] [dir]\n")

def test_HOME_not_set():
    script_tester.test("builtin/cd/test_errors/HOME_not_set.sh",
        expected_stdout = "1\n",
        expected_stderr = "minishell: cd: HOME not set\n")

@pytest.mark.skip(reason="デバッグの時用")
def test_OLDPWD_not_set():
    script_tester.test("builtin/cd/test_errors/OLDPWD_not_set.sh",
        expected_stdout = "1\n",
        expected_stderr = "minishell: cd: OLDPWD not set\n")

@pytest.mark.skip(reason="デバッグの時用")
def test_getcwd_error():
    script_tester.test("builtin/cd/test_errors/getcwd_error.sh",
        expected_stdout = (
            "/app/tests/pytest/builtin/cd/test_errors\n"
            "/app/tests/pytest/builtin/cd/test_errors/tmp/.\n"),
        expected_stderr = (
            "cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n"
            ))
