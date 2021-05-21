// https://leetcode.com/problems/flood-fill/

#include <vector>
#include <queue>
#include <utility>

#ifndef ALGORITHMICCHALLENGES_733_FLOODFILL_H
#define ALGORITHMICCHALLENGES_733_FLOODFILL_H
std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor)
        return image;

    std::vector<std::vector<bool>> visited(image.size(), std::vector<bool>(image.front().size(), false));
    int orignialColor = image[sr][sc];
    std::queue<pair<int, int>> q;
    q.emplace(sr, sc);
    while (!q.empty()) {
        auto next = q.front();
        q.pop();
        image[next.first][next.second] = newColor;
        if (next.first > 0 && image[next.first - 1][next.second] == orignialColor)
            q.emplace(next.first - 1, next.second);
        if (next.first < image.size() - 1 && image[next.first + 1][next.second] == orignialColor)
            q.emplace(next.first + 1, next.second);
        if (next.second > 0 && image[next.first][next.second - 1] == orignialColor)
            q.emplace(next.first, next.second - 1);
        if (next.second < image.front().size() - 1 && image[next.first][next.second + 1] == orignialColor)
            q.emplace(next.first, next.second + 1);
    }
    return image;
}

#endif //ALGORITHMICCHALLENGES_733_FLOODFILL_H
