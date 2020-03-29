//https://leetcode.com/problems/robot-room-cleaner/
#ifndef ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H
#define ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H

#include <unordered_set>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
#include <stack>

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

struct Pos {
    int x_ = 0;
    int y_ = 0;

    bool operator==(const Pos& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Pos& other) const {
        return !(*this == other);
    }
};

struct pos_hash {
    std::size_t operator () (const Pos& cell) const {
        auto h1 = std::hash<int>()(cell.x_);
        auto h2 = std::hash<int>()(cell.y_);
        return h1 ^ h2;
    }
};

enum class RobotDirection {
    Up,
    Right,
    Down,
    Left
};

RobotDirection nextDirectionClockWise(RobotDirection direction) {
    switch (direction) {
        case RobotDirection ::Up:
            return RobotDirection ::Right;
        case RobotDirection ::Right:
            return RobotDirection ::Down;
        case RobotDirection ::Down:
            return RobotDirection ::Left;
        case RobotDirection ::Left:
            return RobotDirection ::Up;
    }
}

class SoltutionSpiralBacktracking {
public:
    Robot* robot_ = nullptr;
    Pos pos_;
    RobotDirection direction_ = RobotDirection::Up;
    unordered_set<Pos, pos_hash> visited_;
    stack<Pos> path_;

Pos getNextPos() const {
    Pos pos = pos_;
    switch (direction_) {
        case RobotDirection ::Up:
            ++pos.y_;
            break;
        case RobotDirection ::Right:
            ++pos.x_;
            break;
        case RobotDirection ::Down:
            --pos.y_;
            break;
        case RobotDirection ::Left:
            --pos.x_;
            break;
    }
    return pos;
}

void turnRight() {
    robot_->turnRight();
    direction_ = nextDirectionClockWise(direction_);
}

void cleanRoom(Robot& robot) {
    robot_ = &robot;
    pos_ = Pos{};
    direction_ = RobotDirection::Up;
    visited_.clear();
    path_ = stack<Pos>{};

    robot.clean();
    visited_.insert(pos_);

    for(;;) {
        bool moved = false;
        for (int i = 0; i < 4; ++i) {
            auto nextPos = getNextPos();
            if (visited_.find(nextPos) == end(visited_)) {
                visited_.insert(nextPos);
                if (robot_->move()) {
                    path_.push(pos_);
                    pos_ = nextPos;
                    robot_->clean();
                    moved = true;
                    break;
                }
            }
            turnRight();
        }

        if (!moved) {
            if (path_.empty())
                return;
            while (getNextPos() != path_.top()) {
                turnRight();
            }

            robot_->move();
            pos_ = path_.top();
            path_.pop();
        }
    }
}

};

#endif //ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H
