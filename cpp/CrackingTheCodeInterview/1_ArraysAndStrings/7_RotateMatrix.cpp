#include "7_RotateMatrix.h"

void rotate(std::vector<std::vector<int>>& matrix) {
    for (std::size_t row = 0; row < matrix.size() / 2; ++row) {
        for (std::size_t column = row; column < matrix.size() - row - 1; ++column) {
            std::swap(matrix[row][column], matrix[column][matrix.size() - 1 - row]);
            std::swap(matrix[row][column], matrix[matrix.size() - 1 - row][matrix.size() - 1 - column]);
            std::swap(matrix[row][column], matrix[matrix.size() - 1 - column][row]);
        }
    }
}

