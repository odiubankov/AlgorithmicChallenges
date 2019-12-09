//https://leetcode.com/problems/range-sum-query-2d-mutable/
#ifndef ALGORITHMICCHALLENGES_308_RANGESUMQUERY2DMUTABLE_H
#define ALGORITHMICCHALLENGES_308_RANGESUMQUERY2DMUTABLE_H

#include <vector>
using namespace std;
class NumMatrix {
    vector<vector<int>> matrix_;
    vector<vector<int>> fenwickTree_;

    void updateImpl(int row, int col, int diff) {
        for (int i = row + 1; i < fenwickTree_.size(); i += (i & (-i))) {
            for (int j = col + 1; j < fenwickTree_[i].size(); j += (j & (-j))) {
                fenwickTree_[i][j] += diff;
            }
        }
    }

    int getSumUntil(int row, int col) {
        int sumUntilCell = 0;
        for (int i = row + 1; i > 0; i -= (i & (-i))) {
            for (int j = col + 1; j > 0; j -= (j & (-j))) {
                sumUntilCell += fenwickTree_[i][j];
            }
        }
        return sumUntilCell;
    }

public:
    NumMatrix(vector<vector<int>> matrix)
    : matrix_{move(matrix)}
    , fenwickTree_(matrix_.size() + 1, vector<int>( matrix_.empty() ? 0 : matrix_.front().size() + 1, 0)) {
        for (int i = 0; i < matrix_.size(); ++i) {
            for (int j = 0; j < matrix_[i].size(); ++j) {
                updateImpl(i, j, matrix_[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        updateImpl(row, col, val - matrix_[row][col]);
        matrix_[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSumUntil(row2, col2) +
            getSumUntil(row1 - 1, col1 - 1) -
            getSumUntil(row1 - 1, col2) -
            getSumUntil(row2, col1 - 1);
    }
};
#endif //ALGORITHMICCHALLENGES_308_RANGESUMQUERY2DMUTABLE_H
