//https://leetcode.com/problems/robot-room-cleaner/
#ifndef ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H
#define ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H

#include <unordered_set>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

enum class Direction;
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

    pair<int, int> pos;
    Direction direct;
    vector<vector<int>> grid;
};

using Cell = pair<int, int>;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};
using CellSetT = unordered_set<Cell, pair_hash>;

enum class Direction{
    Up, Down, Left, Right
};

struct Route {
    Cell cell;
    size_t prev = numeric_limits<size_t>::max();
};

void insertIfPossible(const Cell& pos, const CellSetT& cleaned, const CellSetT& blocked, CellSetT& toClean) {
    if (cleaned.find(pos) == end(cleaned) && blocked.find(pos) == end(blocked))
        toClean.insert(pos);
}

Cell getNext(Cell pos, Direction direct) {
    switch (direct) {
        case Direction::Up: {
            --pos.first;
            break;
        }
        case Direction::Down: {
            ++pos.first;
            break;
        }
        case Direction::Left: {
            --pos.second;
            break;
        }
        case Direction::Right: {
            ++pos.second;
            break;
        }
    }
    return pos;
}

bool checkCell(const Cell& pos, const CellSetT& cleaned, const CellSetT& blocked, const CellSetT& toClean) {
    return cleaned.find(pos) == end(cleaned) && blocked.find(pos) == end(blocked) && toClean.find(pos) != end(toClean);
}

void cleanCell(Robot& robot, const Cell& pos, CellSetT& cleaned, const CellSetT& blocked, CellSetT& toClean) {
    robot.clean();
    toClean.erase(pos);
    cleaned.insert(pos);
    insertIfPossible(Cell{ pos.first - 1, pos.second }, cleaned, blocked, toClean);
    insertIfPossible(Cell{ pos.first + 1, pos.second }, cleaned, blocked, toClean);
    insertIfPossible(Cell{ pos.first, pos.second - 1 }, cleaned, blocked, toClean);
    insertIfPossible(Cell{ pos.first, pos.second + 1 }, cleaned, blocked, toClean);
}

bool moveAndClean(Robot& robot, CellSetT& cleaned, CellSetT& blocked, CellSetT& toClean, const Cell& cell) {
    if (robot.move()) {
        cleanCell(robot, cell, cleaned, blocked, toClean);
        return true;
    } else {
        blocked.insert(cell);
        toClean.erase(cell);
        return false;
    }
}

void doRouteStep(
    queue<size_t>& routes,
    vector<Route>& routesMemory,
    size_t current,
    Direction direct,
    CellSetT& visited,
    const CellSetT& blocked,
    const CellSetT& cleaned) {
    Cell next = getNext(routesMemory[current].cell, direct);
    if (visited.find(next) == end(visited) &&
        blocked.find(next) == end(blocked)) {
        visited.insert(next);
        Route r;
        r.prev = current;
        r.cell = next;
        routesMemory.push_back(r);
        routes.push(routesMemory.size() - 1);
    }
}

void rotateToNext(const Cell& pos, const Cell& next, Direction& dir, Robot& robot) {
    if (next.second < pos.second) {
        if (dir == Direction::Left) {
            return;
        } else if (dir == Direction::Right) {
            robot.turnLeft();
            robot.turnLeft();
        } else if (dir == Direction::Up) {
            robot.turnLeft();
        } else {
            robot.turnRight();
        }
        dir = Direction::Left;
    }
    else if (next.second > pos.second) {
        if (dir == Direction::Left) {
            robot.turnLeft();
            robot.turnLeft();
        } else if (dir == Direction::Right) {
            return;
        } else if (dir == Direction::Up) {
            robot.turnRight();
        } else {
            robot.turnLeft();
        }
        dir = Direction::Right;
    }
    else if (next.first < pos.first) {
        if (dir == Direction::Left) {
            robot.turnRight();
        } else if (dir == Direction::Right) {
            robot.turnLeft();
        } else if (dir == Direction::Up) {
            return;
        } else {
            robot.turnLeft();
            robot.turnLeft();
        }
        dir = Direction::Up;
    }
    else {
        if (dir == Direction::Left) {
            robot.turnLeft();
        } else if (dir == Direction::Right) {
            robot.turnRight();
        } else if (dir == Direction::Up) {
            robot.turnLeft();
            robot.turnLeft();
        } else {
            return;
        }
        dir = Direction::Down;
    }
}

void cleanRoom(Robot& robot) {
    auto direct = Direction::Up;
    Cell pos{1, 3};
    CellSetT cleaned{}, blocked{}, toClean;
    cleanCell(robot, pos, cleaned, blocked, toClean);
    while (!toClean.empty()) {
        Cell next = getNext(pos, direct);
        if (checkCell(next, cleaned, blocked, toClean) &&
            moveAndClean(robot, cleaned, blocked, toClean, next)) {
            pos = next;
        } else {
            CellSetT visited;
            vector<Route> routesMemory;
            queue<size_t> routes;
            {
                Route r;
                r.cell = pos;
                routesMemory.push_back(r);
                routes.push(0);
                visited.insert(pos);
            }
            while (!routes.empty() && toClean.find(routesMemory[routes.front()].cell) == end(toClean)) {
                auto current = routes.front();
                routes.pop();
                doRouteStep(routes, routesMemory, current, Direction::Left, visited, blocked, cleaned);
                doRouteStep(routes, routesMemory, current, Direction::Right, visited, blocked, cleaned);
                doRouteStep(routes, routesMemory, current, Direction::Up, visited, blocked, cleaned);
                doRouteStep(routes, routesMemory, current, Direction::Down, visited, blocked, cleaned);
            }
            if (routes.empty())
                return;
            auto r =  routes.front();
            vector<Cell> cellsToGo;
            while (r != numeric_limits<size_t>::max()) {
                cellsToGo.push_back(routesMemory[r].cell);
                r = routesMemory[r].prev;
            }
            reverse(begin(cellsToGo), end(cellsToGo));
            for (auto it = begin(cellsToGo) + 1; it != end(cellsToGo) - 1; ++it) {
                rotateToNext(pos, *it, direct, robot);
                robot.move();
                pos = *it;
            }
            rotateToNext(pos, cellsToGo.back(), direct, robot);
            if (moveAndClean(robot, cleaned, blocked, toClean, cellsToGo.back()))
                pos = cellsToGo.back();
        }
    }
}

#endif //ALGORITHMICCHALLENGES_489_ROBOTROOMCLEANER_H
