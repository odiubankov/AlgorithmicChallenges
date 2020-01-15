#include "489_RobotRoomCleaner.h"
#include <gtest/gtest.h>

//Robot::Robot()
//: pos{1, 3}
//, direct{Direction::Up}
//, grid {
//    {1,1,1,1,1,0,1,1},
//    {1,1,1,1,1,0,1,1},
//    {1,0,1,1,1,1,1,1},
//    {0,0,0,1,0,0,0,0},
//    {1,1,1,1,1,1,1,1}
//    }
//{}
//
//bool Robot::move() {
//    Cell next = pos;
//    switch (direct) {
//        case Direction::Up: {
//            --next.first;
//            break;
//        }
//        case Direction::Down: {
//            ++next.first;
//            break;
//        }
//        case Direction::Left: {
//            --next.second;
//            break;
//        }
//        case Direction::Right: {
//            ++next.second;
//            break;
//        }
//    }
//    if (next.first < grid.size() &&
//        next.first >= 0 &&
//        next.second < grid.front().size() &&
//        next.second >= 0 &&
//        grid[next.first][next.second] != 0) {
//        pos = next;
//        return true;
//    }
//    return false;
//}
//
//void Robot::turnLeft() {
//    switch (direct) {
//        case Direction::Up:
//            direct = Direction::Left;
//            break;
//        case Direction::Left:
//            direct = Direction::Down;
//            break;
//        case Direction::Down:
//            direct = Direction::Right;
//            break;
//        case Direction::Right:
//            direct = Direction::Up;
//            break;
//    }
//}
//
//void Robot::turnRight() {
//    switch (direct) {
//        case Direction::Up:
//            direct = Direction::Right;
//            break;
//        case Direction::Left:
//            direct = Direction::Up;
//            break;
//        case Direction::Down:
//            direct = Direction::Left;
//            break;
//        case Direction::Right:
//            direct = Direction::Down;
//            break;
//    }
//}
//
//void Robot::clean() {
//    grid[pos.first][pos.second] = 2;
//}
//
//TEST(Robot, test) {
//    Robot r;
//    cleanRoom(r);
//    for (const auto& row : r.grid) {
//        for (auto cell : row) {
//            ASSERT_NE(1, cell);
//        }
//    }
//}
