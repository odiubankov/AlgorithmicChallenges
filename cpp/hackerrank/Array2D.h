#ifndef ALGORITHMICCHALLENGES_ARRAY2D_H
#define ALGORITHMICCHALLENGES_ARRAY2D_H

#include <array>
#include <limits>

namespace hackerrank
{

int hourglassSum(const std::array<std::array<int, 6>, 6>& array2d)
{
    int result = std::numeric_limits<int>::min();
    for (int i = 0; i <= 3; ++i)
    {
        for (int j = 0; j <= 3; ++j)
        {
            int sum = array2d[i][j] + array2d[i][j + 1] + array2d[i][j + 2];
            sum += array2d[i + 1][j + 1];
            sum += array2d[i + 2][j] + array2d[i + 2][j + 1] + array2d[i + 2][j + 2];
            result = std::max(result, sum);
        }
    }

    return result;
}

}

#endif //ALGORITHMICCHALLENGES_ARRAY2D_H
