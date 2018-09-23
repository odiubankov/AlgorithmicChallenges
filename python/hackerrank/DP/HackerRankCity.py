import pytest
import sys

MODULO = 1000000007


def hackerrank_city(edges):
    a_pr = 1
    s_pr = 0
    m_pr = 0
    se_pr = 0
    for l in edges:
        a = (a_pr * 4 + 2) % MODULO
        m = ((2 * m_pr) % MODULO + (3 * l) % MODULO) % MODULO
        s = (4 * s_pr) % MODULO
        s += ((((l * a_pr) % MODULO + se_pr) % MODULO) * 4) % MODULO
        s %= MODULO
        s += ((((2 * l * a_pr) % MODULO + se_pr) % MODULO) * 4) % MODULO
        s %= MODULO
        s += ((((2 * l * pow(a_pr, 2, MODULO)) % MODULO + (2 * a_pr * se_pr) % MODULO) % MODULO) * 2) % MODULO
        s %= MODULO
        s += ((((3 * l * pow(a_pr, 2, MODULO)) % MODULO + (2 * a_pr * se_pr) % MODULO) % MODULO) * 4) % MODULO
        s %= MODULO
        s += l
        s %= MODULO
        se = se_pr
        se += ((((m_pr + (2 * l) % MODULO) % MODULO) * a_pr) % MODULO + se_pr) % MODULO
        se %= MODULO
        se += ((((((m_pr + (3 * l) % MODULO) % MODULO) * a_pr) % MODULO + se_pr) % MODULO) * 2) % MODULO
        se %= MODULO
        se += (m_pr + l + m_pr + (2 * l) % MODULO) % MODULO
        se %= MODULO
        a_pr = a
        m_pr = m
        s_pr = s
        se_pr = se
    return s


def test_hackerrank_city():
    assert hackerrank_city([1]) == 29
    assert hackerrank_city([2, 1]) == 2641


if __name__ == '__main__':
    pytest.main(sys.argv)
