import script_tester
import pytest
import subprocess

testdir = "builtin/cd/test_basic/"

def	test_move_current():
	args = ["cd .\necho $PWD\ncd ./\necho $PWD\n"]
	result=subprocess.run(args,shell=True,capture_output=True,text=True)
	script_tester.test(testdir + "test_move_current.sh",
        expected_stdout = result.stdout,
        expected_stderr = result.stderr)
	
def	test_move_parent():
	args = ["cd ..\necho $PWD\ncd $OLDPWD\ncd ../\n"
	"echo $PWD\n", "cd $OLDPWD"]
	result=subprocess.run(args,shell=True,capture_output=True,text=True)
	script_tester.test(testdir + "test_move_parent.sh",
        expected_stdout = result.stdout,
        expected_stderr = result.stderr)
