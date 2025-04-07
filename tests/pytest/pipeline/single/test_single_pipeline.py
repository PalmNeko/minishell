import script_tester
import pytest

def test_single_quote_word():
	script_tester.test("pipeline/single/test_single_quoted_word.sh",
		expected_stdout = "Hello$HOGE*~\n",
		expected_stderr = ""
	)

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

# @pytest.mark.skip(reason="該当issueで修正予定のため")
# echo "$HOGE" -> OK, echo "some_string,$HOGE" -> NG 
def test_double_quote_variable():
	script_tester.test("pipeline/single/test_double_quoted_word_variable.sh",
		expected_stdout = "hoge\nsome_string,hoge\n",
		expected_stderr = ""
	)

def test_double_quote_blank():
	script_tester.test("pipeline/single/test_double_quoted_word_blank.sh",
		expected_stdout = "Hello   World\n",
		expected_stderr = ""
	)
	
def test_variable_before_string():
	script_tester.test("pipeline/single/test_variable_before_join_string.sh",
		expected_stdout = "Hellohoge\nHellohoge 2\n",
		expected_stderr = ""
	)

def test_syntax_error():
	script_tester.test("pipeline/single/test_syntax_error_status.sh",
		expected_stdout = "2\n0\n",
		expected_stderr = "minishell: syntax error near unexpected token `('\n"
	)
