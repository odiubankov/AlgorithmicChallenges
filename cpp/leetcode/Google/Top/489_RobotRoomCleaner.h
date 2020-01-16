//https://leetcode.com/problems/robot-room-cleaner/
#ifndef ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H
#define ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H

#include <unordered_set>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
  public:
    Robot();
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();

//    pair<int, int> pos;
//    Direction direct;
//    vector<vector<int>> grid;
};

struct Direction {
    int x = 0;
    int y = 0;

    bool operator==(const Direction& direction) const {
        return x == direction.x && y == direction.y;
    }

    bool operator!=(const Direction& direction) const {
        return !(*this == direction);
    }

    Direction& operator=(const Direction& direction) {
        if (this == &direction)
            return *this;
        x = direction.x;
        y = direction.y;
        return *this;
    }
};

struct Cell {
    int x = 0;
    int y = 0;

    Cell& operator+=(const Direction& direction) {
        x += direction.x;
        y += direction.y;
        return *this;
    }

    bool operator==(const Cell& cell) const {
        return x == cell.x && y == cell.y;
    }
};

struct cell_hash {
    std::size_t operator () (const Cell& cell) const {
        std::size_t h1 = std::hash<int>()(cell.x);
        std::size_t h2 = std::hash<int>()(cell.y);
        return h1 ^ h2;
    }
};

using CellSetT = unordered_set<Cell, cell_hash>;

class SolutionCleanRoom
{
private:
    const Direction Up{0, 1}, Down{0, -1}, Left{-1, 0}, Right{1, 0};
    const vector<Direction> Directions{Up, Down, Left, Right};

    CellSetT cleaned_, blocked_, toClean_;
    Cell pos_{0, 0};
    Direction direction_ = Up;

    void addCellsToClean() {
        for (const auto& direction : Directions) {
            auto nextCell = pos_;
            nextCell += direction;
            if (blocked_.find(nextCell) == end(blocked_) && cleaned_.find(nextCell) == end(cleaned_))
                toClean_.insert(nextCell);
        }
    }

    bool getRouteToNext(Cell pos, vector<Direction>& directions, CellSetT& visited) const {
        if (toClean_.find(pos) != end(toClean_))
            return true;
        visited.insert(pos);
        for (const auto& direction : Directions) {
            auto nextPos = pos;
            nextPos += direction;
            if (visited.find(nextPos) == end(visited) &&
                blocked_.find(nextPos) == end(blocked_)) {
                if (getRouteToNext(nextPos, directions, visited)) {
                    directions.push_back(direction);
                    return true;
                }
            }
        }
        return false;
    }

    void rotateToDirection(Robot &robot, const Direction& direction) {
        while (direction_ != direction) {
            robot.turnRight();
            if (direction_ == Up)
                direction_ = Right;
            else if (direction == Right)
                direction_ = Down;
            else if (direction == Down)
                direction_ = Left;
            else
                direction_ = Up;
        }
    }

public:
    void cleanRoomDFS(Robot &robot) {
        robot.clean();
        cleaned_.insert(pos_);
        addCellsToClean();
        while (!toClean_.empty()) {
            CellSetT visited;
            vector<Direction> directions;
            getRouteToNext(pos_, directions, visited);
            reverse(begin(directions), end(directions));
            for (auto directionIt = begin(directions); directionIt != end(directions) - 1; ++directionIt) {
                rotateToDirection(robot, *directionIt);
                robot.move();
                pos_ += *directionIt;
            }
            rotateToDirection(robot, directions.back());
            if (robot.move()) {
                robot.clean();
                pos_ += directions.back();
                toClean_.erase(pos_);
                cleaned_.insert(pos_);
                addCellsToClean();
            } else {
                auto blockedCell = pos_;
                blockedCell += directions.back();
                toClean_.erase(blockedCell);
                blocked_.insert(blockedCell);
            }
        }
    }
};

#endif //ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H
