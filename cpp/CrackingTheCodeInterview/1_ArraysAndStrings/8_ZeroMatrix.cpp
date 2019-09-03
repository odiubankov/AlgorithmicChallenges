#include "8_ZeroMatrix.h"

#include <algorithm>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
        return;

    auto firstRowIt = begin(matrix);
    bool firstRowZero = any_of(begin(*firstRowIt), end(*firstRowIt), [](int val) { return val == 0; });
    auto firstColZero = any_of(begin(matrix), end(matrix), [](const auto& row) { return row[0] == 0; });
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < matrix[0].size(); ++i) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < matrix.size(); ++j) {
                matrix[j][i] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero) {
        for (int i = 0; i < matrix[0].size(); ++i) {
            matrix[0][i] = 0;
        }
    }

    if (firstColZero) {
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][0] = 0;
        }
    }
}
