import os
import sys
sys.path.append(os.getcwd())

def test_a():
    p = subprocess.Popen(
        ["bash", "test_script.sh"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE
    )
    # 標準出力のテスト
    # 標準エラー出力のテスト

def multiplication(x, y):
    return x * y
