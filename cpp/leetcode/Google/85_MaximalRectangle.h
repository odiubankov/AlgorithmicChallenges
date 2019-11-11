//https://leetcode.com/problems/maximal-rectangle/
#ifndef ALGORITHMICCHALLENGES_85_MAXIMALRECTANGLE_H
#define ALGORITHMICCHALLENGES_85_MAXIMALRECTANGLE_H

#include <vector>
#include <queue>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.front().empty())
        return 0;
    vector<vector<int>> width(matrix.size(), vector<int>(matrix.front().size(), 0));
    auto height = width;
    for (int i = matrix.size() - 1; i >= 0; --i) {
        for (int j = matrix[i].size() - 1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                if (j != (matrix[i].size() - 1))
                    width[i][j] = width[i][j + 1] + 1;
                else
                    width[i][j] = 1;

                if (i != (matrix.size() - 1))
                    height[i][j] = height[i + 1][j] + 1;
                else
                    height[i][j] = 1;
            }
        }
    }
    int maxRect = 0;
    for (int i = 0; i < matrix.size() - (maxRect / matrix.front().size()); ++i) {
        for (int j = 0; j < matrix[i].size() - (maxRect / matrix.size()); ++j) {
            if (width[i][j] != 0) {
                int minHeight = height[i][j];
                for (int k = 0; k < width[i][j]; ++k) {
                    minHeight = min(minHeight, height[i][j + k]);
                    int rect = (k + 1) * minHeight;
                    maxRect = max(maxRect, rect);
                }
            }
        }
    }

    return maxRect;
}

int maximalRectangleDP(vector<vector<char>>& matrix) {
    if (matrix.empty())
        return 0;
    int x = matrix.front().size();
    int y = matrix.size();
    std::vector<int> height(x, 0), l(x, 0), r(x, x - 1);
    int maxRect = 0, left = 0, right = x - 1;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (matrix[i][j] == '1') {
                ++height[j];
                l[j] = max(l[j], left);
            } else {
                left = j + 1;
                height[j] = 0;
                l[j] = 0;
            }
        }
        for (int j = x - 1; j >=0; --j) {
            if (matrix[i][j] == '1') {
                r[j] = min(r[j], right);
                auto rect = height[j] * (r[j] - l[j] + 1);
                maxRect = max(maxRect, rect);
            } else {
                r[j] = x - 1;
                right = j - 1;
            }
        }
        left = 0;
        right = x - 1;
    }
    return maxRect;
}

#endif //ALGORITHMICCHALLENGES_85_MAXIMALRECTANGLE_H
