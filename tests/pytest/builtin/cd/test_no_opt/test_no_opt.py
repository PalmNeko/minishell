import script_tester
import pytest

@pytest.mark.skip(reason="pwdの出力がバッファリングされる関係でスキップ")
def test_basic_usage():
    script_tester.test("builtin/cd/test_no_opt/can_change_directory.sh",
		expected_stdout= (
			"/app/tests/pytest/builtin/cd/test_no_opt/physical_dir\n"
			"/app/tests/pytest/builtin/cd/test_no_opt/symbolic_dir\n"
			))
