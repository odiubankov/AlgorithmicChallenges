from functools import *


@lru_cache(maxsize=None)
def get_all_wall_cnt(w, h):
    if w == 0:
        return 0
    if h == 1:
        result = 0
        for i in range(1, 5):
            if w > i:
                result += get_all_wall_cnt(w - i, 1)
            elif w == i:
                result += 1
        return result
    height1_cnt = get_all_wall_cnt(w, 1)
    result = height1_cnt
    for _ in range(1,h):
        result *= height1_cnt
    return result


@lru_cache(maxsize=None)
def get_gap_cnt(w, h, n):
    if w <= 1:
        return 0
    result = 0
    for i in range(1, w):
        left_cnt = get_all_wall_cnt(i, h) - get_all_gap_cnt(i, h)
        right_cnt = 0
        if n == 1:
            right_cnt = get_all_wall_cnt(w - i, h) - get_all_gap_cnt(w - i, h)
        else:
            right_cnt = get_gap_cnt(w - i, h, n - 1)
        result += (left_cnt * right_cnt)
    return result


def get_all_gap_cnt(w, h):
    if w <= 1:
        return 0
    result = 0
    for i in range(1, w):
        result += get_gap_cnt(w, h, i)
    return result


def get_stable_wall_cnt(w, h):
    result = get_all_wall_cnt(w, h)
    gap_cnt = get_all_gap_cnt(w, h)
    result -= gap_cnt
    result %= 1000000007
    return result
