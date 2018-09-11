import pytest
import sys


def max_sub_array(arr):
    if not arr:
        return [0, 0]
    if all(i < 0 for i in arr):
        max_element = max(arr)
        return [max_element, max_element]
    sub_sequence_max = 0
    current_sum = 0
    sub_arrays = []
    for val in arr:
        if val > 0:
            sub_sequence_max += val
            if current_sum < 0:
                sub_arrays.append(current_sum)
                current_sum = 0
        elif val < 0:
            if current_sum > 0:
                sub_arrays.append(current_sum)
                current_sum = 0
        current_sum += val
    sub_arrays.append(current_sum)
    merged = True
    while merged:
        merged = False
        if sub_arrays[0] < 0:
            sub_arrays.pop(0)
        if sub_arrays[-1] < 0:
            sub_arrays.pop(-1)
        if len(sub_arrays) >= 3:
            for i in range(len(sub_arrays) - 2, 0, -2):
                abs_val = abs(sub_arrays[i])
                if abs_val <= sub_arrays[i - 1] and abs_val <= sub_arrays[i + 1]:
                    merged = True
                    new_val = sub_arrays[i - 1] + sub_arrays[i] + sub_arrays[i + 1]
                    sub_arrays.pop(i + 1)
                    sub_arrays.pop(i)
                    sub_arrays[i - 1] = new_val
    return [max(sub_arrays), sub_sequence_max]


def test_max_sub_array_1():
    assert max_sub_array([1, 2, 3, 4]) == [10, 10]


def test_max_sub_array_2():
    assert max_sub_array([2, -1, 2, 3, 4, -5]) == [10, 11]


def test_max_sub_array_3():
    assert max_sub_array([-2, -3, -1, -4, -6]) == [-1, -1]


def test_max_sub_array_4():
    assert max_sub_array([-1, 2, 3, -4, 5, 10]) == [16, 20]


if __name__ == '__main__':
    pytest.main(sys.argv)
