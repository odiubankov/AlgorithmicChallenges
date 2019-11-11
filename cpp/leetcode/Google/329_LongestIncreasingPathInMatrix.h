//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#ifndef ALGORITHMICCHALLENGES_329_LONGESTINCREASINGPATHINMATRIX_H
#define ALGORITHMICCHALLENGES_329_LONGESTINCREASINGPATHINMATRIX_H

#include <vector>
using namespace std;

using CacheT = vector<vector<int>>;

int longestIncreasingPathImpl(const vector<vector<int>>& matrix, int i, int j, CacheT& cache) {
    if (cache[i][j] != -1)
        return cache[i][j];
    int path = 1;
    if (j > 0 && matrix[i][j - 1] > matrix[i][j])
        path = max(path, 1 + longestIncreasingPathImpl(matrix, i, j - 1, cache));
    if (j < (matrix[i].size() - 1) && matrix[i][j + 1] > matrix[i][j])
        path = max(path, 1 + longestIncreasingPathImpl(matrix, i, j + 1, cache));
    if (i > 0 && matrix[i - 1][j] > matrix[i][j])
        path = max(path, 1 + longestIncreasingPathImpl(matrix, i - 1, j, cache));
    if (i < (matrix.size() - 1) && matrix[i + 1][j] > matrix[i][j])
        path = max(path, 1 + longestIncreasingPathImpl(matrix, i + 1, j, cache));
    cache[i][j] = path;
    return path;
}

int longestIncreasingPath(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty())
        return 0;
    int longestPath = 0;
    CacheT cache(matrix.size(), vector<int>(matrix.front().size(), -1));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            int path = longestIncreasingPathImpl(matrix, i, j, cache);
            if (path > longestPath)
                longestPath = path;
        }
    }
    return longestPath;
}

#endif //ALGORITHMICCHALLENGES_329_LONGESTINCREASINGPATHINMATRIX_H
