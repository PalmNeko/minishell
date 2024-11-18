import script_checker
import pytest

def test_sample():
    script_checker.run_checker("sample/sample1.sh", "仕様の説明")

@pytest.mark.skip(reason="ここに理由を記載する")
def test_skip_sample():
    # 実装はまだだけどテストを先に書くときなどに使用
    # テストがまだうまく動作しないときなどにも使用できる
    # テスト
    pass
