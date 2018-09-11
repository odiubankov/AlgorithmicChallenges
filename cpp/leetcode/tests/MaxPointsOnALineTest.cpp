#include "../MaxPointsOnALine.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(MaxPoints, test)
{
    Solution solution;
    std::vector<Point> points{Point{0, 0}, Point {1, 1}, Point {2, 2}};
    EXPECT_EQ(3, solution.maxPoints(points));

    std::vector<Point> points2{Point{0, 0}, Point {1, 1}, Point {0, 0}};
    EXPECT_EQ(3, solution.maxPoints(points2));

    std::vector<Point> points3{Point{1, 1}, Point {1, 1}, Point {1, 1}};
    EXPECT_EQ(3, solution.maxPoints(points3));

    std::vector<Point> points4{Point{0, 0}, Point {94911151, 94911150}, Point {94911152, 94911151}};
    EXPECT_EQ(2, solution.maxPoints(points4));
}

}//namespace leetcode

