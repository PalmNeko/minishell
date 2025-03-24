import script_tester
import pytest
import subprocess

def test_single_quote_word():
	script_tester.test("pipeline/single/test_single_quoted_word.sh",
		expected_stdout = "Hello$HOGE*~\n",
		expected_stderr = ""
	)

@pytest.mark.skip(reason="該当issueで修正予定のため")
def test_single_quote_word_blank():
	script_tester.test("pipeline/single/test_single_quoted_word_blank.sh",
		expected_stdout = "Hello  World\n",
		expected_stderr = ""
	)

def test_double_quote_word():
	script_tester.test("pipeline/single/test_double_quoted_word.sh",
		expected_stdout = "Hello*~\n",
		expected_stderr = ""
	)

@pytest.mark.skip(reason="該当issueで修正予定のため")
def test_double_quote_valiable():
	script_tester.test("pipeline/single/test_double_quoted_word.sh",
		expected_stdout = "Hello,hoge\n",
		expected_stderr = ""
	)

@pytest.mark.skip(reason="該当issueで修正予定のため")
def test_double_quote_blank():
	script_tester.test("pipeline/single/test_double_quoted_word.sh",
		expected_stdout = "Hello   World\n",
		expected_stderr = ""
	)