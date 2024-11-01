import os
import sys
sys.path.append(os.getcwd())

def test_a():
    assert 6 == multiplication(2, 3)

def multiplication(x, y):
    return x * y
