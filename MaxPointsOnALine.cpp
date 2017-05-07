#include "MaxPointsOnALine.h"
#include <gtest/gtest.h>


TEST(MaxPoints, test)
{
    using namespace maxpointsonaline;
    Solution solution;
//    vector<Point> points{ Point{0, 0}, Point {1, 1}, Point {2, 2} };
//    EXPECT_EQ(3, solution.maxPoints(points));
//
//    vector<Point> points2{ Point{0, 0}, Point {1, 1}, Point {0, 0} };
//    EXPECT_EQ(3, solution.maxPoints(points2));
//
//    vector<Point> points3{ Point{1, 1}, Point {1, 1}, Point {1, 1} };
//    EXPECT_EQ(3, solution.maxPoints(points3));

    vector<Point> points4{ Point{0, 0}, Point {94911151, 94911150}, Point {94911152,94911151} };
    EXPECT_EQ(2, solution.maxPoints(points4));
}
