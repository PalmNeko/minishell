import os
import sys
import subprocess
import re
import logging
from test.support import captured_stdout
sys.path.append(os.getcwd())

def run_checker(script_file: str, title: str) -> bool:
    stdout_file = re.sub('.sh$', '_stdout.log', script_file)
    expected_stdout_file = re.sub('.sh$', '_stdout.txt', script_file)
    stderr_file = re.sub('.sh$', '_stderr.log', script_file)
    expected_stderr_file = re.sub('.sh$', '_stderr.txt', script_file)
    result = run_script(script_file, stdout_file, stderr_file)
    logger = TestLogger(title, script_file)
    try:
        assert_status(logger, result.returncode)
        assert_stdout(logger, stdout_file, expected_stdout_file)
        assert_stderr(logger, stderr_file, expected_stderr_file)
    except AssertionError as e:
        logging.error("\n" + logger.make_diff())
        raise

def run_script(script_file, stdout_file, stderr_file):
    with open(stdout_file, "w") as stdout, open(stderr_file, "w") as stderr:
        result = subprocess.run(["bash", script_file], stdout=stdout, stderr=stderr, text=True)
        return result

def assert_status(logger, returncode):
    logger.set_status(returncode)
    logger.set_description("終了ステータス")
    assert returncode == 0, logger.create_message_status()

def assert_stdout(logger, stdout_file, expected_stdout_file):
    actual_output, expected_output = get_actual_and_expected(stdout_file, expected_stdout_file)
    logger.set_description("標準出力")
    logger.set_file(stdout_file, expected_stdout_file)
    assert actual_output == expected_output, logger.create_message()

def assert_stderr(logger, stderr_file, expected_stderr_file):
    actual_output, expected_output = get_actual_and_expected(stderr_file, expected_stderr_file)
    logger.set_description("標準エラー出力")
    logger.set_file(stderr_file, expected_stderr_file)
    assert actual_output == expected_output, logger.create_message()

def get_actual_and_expected(actual_file, expected_file):
    with open(actual_file, "r") as actual, open(expected_file, "r") as expected:
        actual_output = actual.read()
        expected_output = expected.read()
        return [actual_output, expected_output]

class TestLogger:
    def __init__(self, spec, script_file):
        self.spec = spec
        self.script_file = script_file

    def set_file(self, actual_file, expected_file):
        self.actual_file = actual_file
        self.expected_file = expected_file

    def set_description(self, description):
        self.description = description

    def set_status(self, status):
        self.status = status

    def create_message_status(self):
        message = f"{self.description}: {self.spec}\n"
        message += f"\tstatus: {self.status}\n"
        message += f"\tscript-file: {self.script_file}\n"
        message += f"\tstatus: {self.status}\n"
        return message

    def create_message(self):
        message = f"{self.description}: {self.spec}\n"
        message += f"\tscript-file: {self.script_file}\n"
        message += f"\tactual-file: {self.actual_file}\n"
        message += f"\texpected-file: {self.expected_file}\n"
        return message

    def make_diff(self):
        message = f"script: {self.script_file}\n"
        if not hasattr(self, "actual_file"):
            if not hasattr(self, "status"):
                return message
            message += f"status: {self.status}\n"
            return message
        command = [
            "diff",
            "-y", "--color=always",
            self.expected_file, self.actual_file]
        result = subprocess.run(command, capture_output=True, text=True)
        message = "$ " + " ".join(command) + "\n"
        message += result.stdout
        return message
