//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
#ifndef ALGORITHMICCHALLENGES_363_MAXSUMOFRECTANGLENOLARGERTHANK_H
#define ALGORITHMICCHALLENGES_363_MAXSUMOFRECTANGLENOLARGERTHANK_H

#include <vector>
#include <limits>
#include <set>
using namespace std;

int maxSumSubmatrix(const vector<vector<int>>& matrix, int k) {
    int maxSum = numeric_limits<int>::min();
    for (size_t colStart = 0; colStart < matrix.front().size(); ++colStart) {
        for (size_t colEnd = colStart + 1; colEnd <= matrix.front().size(); ++colEnd) {
            vector<int> rowSums(matrix.size(), 0);
            for (size_t row = 0; row < matrix.size(); ++row) {
                for (int i = colStart; i < colEnd; ++i)
                    rowSums[row] += matrix[row][i];
            }
            int totalSum = 0;
            set<int> cumulativeSums{0};
            for (int sum : rowSums) {
                totalSum += sum;
                auto csIt = cumulativeSums.lower_bound(totalSum - k);
                if (csIt != end(cumulativeSums)) {
                    int foundSum = totalSum - *csIt;
                    maxSum = max(foundSum, maxSum);
                }
                cumulativeSums.insert(totalSum);
            }
        }
    }
    return maxSum;
}

#endif //ALGORITHMICCHALLENGES_363_MAXSUMOFRECTANGLENOLARGERTHANK_H
