import pytest
import sys


def get_max_experience(mandragoras):
    sorted_mandragoras = sorted(mandragoras)
    left_mandragoras = sum(sorted_mandragoras)
    s = 1
    max_experience = left_mandragoras * s
    for mandragora in sorted_mandragoras:
        s += 1
        left_mandragoras -= mandragora
        experience = s * left_mandragoras
        if experience > max_experience:
            max_experience = experience
    return max_experience


def test_mandragoras_1():
    assert get_max_experience([3, 2, 2]) == 10
    assert get_max_experience([3, 2, 5]) == 16


if __name__ == '__main__':
    pytest.main(sys.argv)
