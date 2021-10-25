//https://leetcode.com/problems/robot-bounded-in-circle/
// On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

// "G": go straight 1 unit;
// "L": turn 90 degrees to the left;
// "R": turn 90 degrees to the right.
// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
#ifndef ROBOT_BOUNDED_IN_CIRCLE_H
#define ROBOT_BOUNDED_IN_CIRCLE_H

#include <string>
#include <functional>
#include <iostream>

// what is the max length of input?
// what shall be done if unrecognized command found?

enum class Direction {
    North,
    South,
    West,
    East
};

struct RobotPos {
    int row = 0;
    int col = 0;
    Direction direction = Direction::North;
};

void turnLeft(RobotPos& robotPos) {
    switch (robotPos.direction) {
        case Direction::North: {
            robotPos.direction = Direction::West;
            break;
        }
        case Direction::South: {
            robotPos.direction = Direction::East;
            break;
        }
        case Direction::West: {
            robotPos.direction = Direction::South;
            break;
        }
        case Direction::East: {
            robotPos.direction = Direction::North;
            break;
        }
    }
}

void turnRight(RobotPos& robotPos) {
    switch (robotPos.direction) {
        case Direction::North: {
            robotPos.direction = Direction::East;
            break;
        }
        case Direction::South: {
            robotPos.direction = Direction::West;
            break;
        }
        case Direction::West: {
            robotPos.direction = Direction::North;
            break;
        }
        case Direction::East: {
            robotPos.direction = Direction::South;
            break;
        }
    }
}

void go(RobotPos& robotPos) {
    switch (robotPos.direction) {
        case Direction::North: {
            --robotPos.row;
            break;
        }
        case Direction::South: {
            ++robotPos.row;
            break;
        }
        case Direction::West: {
            --robotPos.col;
            break;
        }
        case Direction::East: {
            ++robotPos.col;
            break;
        }
    }

    std::cout << "row: " << robotPos.row << "col: " << robotPos.col << std::endl;
}

using ActionT = std::function<void(RobotPos&)>;
ActionT getAction(char instruction) {
    switch (instruction) {
        case 'L':
            return turnLeft;
        case 'R':
            return turnRight;
        case 'G':
            return go;
    }
    return nullptr;
}

void moveRobot(RobotPos& robotPos, const std::string& instructions) {
    for (const auto instruction : instructions) {
        const auto action = getAction(instruction);
        action(robotPos);
    }
}

bool isRobotBounded(const std::string& instructions) {
    RobotPos robotPos;
    for (int i = 0; i < 4; ++i) {
        moveRobot(robotPos, instructions);
    }

    const int firstDist = abs(robotPos.row) + abs(robotPos.col);
    for (int i = 0; i < 4; ++i) {
        moveRobot(robotPos, instructions);
    }

    const int secondDist = abs(robotPos.row) + abs(robotPos.col);
    return firstDist == secondDist;
}

#endif //ROBOT_BOUNDED_IN_CIRCLE_H
