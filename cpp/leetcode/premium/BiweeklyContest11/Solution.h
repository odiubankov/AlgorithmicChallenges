//https://leetcode.com/contest/biweekly-contest-11
#ifndef ALGORITHMICCHALLENGES_SOLUTION_H
#define ALGORITHMICCHALLENGES_SOLUTION_H
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

//vector<string> split(const string& s, char delimiter) {
//    vector<string> tokens;
//    string token;
//    istringstream tokenStream(s);
//    while (getline(tokenStream, token, delimiter))
//        tokens.push_back(token);
//    return tokens;
//}

string toHexspeak(string num) {
    static const unordered_map<char, char> hexChars{
        {'a', 'A'},
        {'b', 'B'},
        {'c', 'C'},
        {'d', 'D'},
        {'e', 'E'},
        {'f', 'F'},
        {'1', 'I'},
        {'0', 'O'}
    };
    std::stringstream stream;
    stream << std::hex << stoll(num);
    auto result = stream.str();
    for (auto& c : result) {
        auto chIt = hexChars.find(c);
        if (chIt == end(hexChars))
            return "ERROR";
        c = chIt->second;
    }
    return result;
}

vector<vector<int>> removeInterval(const vector<vector<int>>& intervals, const vector<int>& toBeRemoved) {
    vector<vector<int>> res;
    for (auto interval : intervals) {
        if (toBeRemoved.back() < interval.front() || toBeRemoved.front() >= interval.back()) {
            res.push_back(interval);
        } else if (toBeRemoved.front() > interval.front() && toBeRemoved.back() < interval.back()) {
            res.push_back({interval.front(), toBeRemoved.front()});
            res.push_back({toBeRemoved.back(), interval.back()});
        } else if (toBeRemoved.front() <= interval.front() && toBeRemoved.back() >= interval.back()) {
        } else if (toBeRemoved.front() < interval.back() && toBeRemoved.back() >= interval.back()) {//3
            res.push_back({interval.front(), toBeRemoved.front()});
        } else if (toBeRemoved.front() <= interval.front() && toBeRemoved.back() > interval.front()) {
            res.push_back({toBeRemoved.back(), interval.back()});
        }
    }
    sort(begin(res), end(res));
    return res;
}

int getChildrenCnt(const vector<unordered_set<int>>& tree, int current, const vector<int>& values, int& sum) {
    int childrenCnt = 0;
    int childrenSum = 0;
    for (auto child : tree[current]) {
        int childSum = 0;
        int childCnt = getChildrenCnt(tree, child, values, childSum);
        if (childSum != 0) {
            childrenCnt += childCnt;
            childrenSum += childSum;
        }
    }
    sum = values[current] + childrenSum;
    return 1 + childrenCnt;
}

int deleteTreeNodes(int nodes, const vector<int>& parent, const vector<int>& value) {
    vector<unordered_set<int>> nodeChildren(nodes, unordered_set<int>{});
    for (size_t i = 1; i < parent.size(); ++i)
        nodeChildren[parent[i]].insert(i);
    int headSum = 0;
    int cnt = getChildrenCnt(nodeChildren, 0, value, headSum);
    if (headSum == 0)
        return 0;
    return cnt;
}

class Sea {
  public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft){ return false; }
};

void countShipsImpl(Sea sea, const vector<int>& topRight, const vector<int>& bottomLeft, int& shipsCnt) {
    if (sea.hasShips(topRight, bottomLeft)) {
        if (topRight == bottomLeft) {
            ++shipsCnt;
        } else {
            if (topRight.front() == bottomLeft.front()) {
                vector<int> newTopRight, newBottomLeft;
                newTopRight.push_back(topRight.front());
                newTopRight.push_back(bottomLeft.back() + ((topRight.back() - bottomLeft.back()) / 2));
                newBottomLeft.push_back(topRight.front());
                newBottomLeft.push_back(newTopRight.back() + 1);
                countShipsImpl(sea, newTopRight, bottomLeft, shipsCnt);
                countShipsImpl(sea, topRight, newBottomLeft, shipsCnt);
            } else {
                vector<int> newTopRight, newBottomLeft;
                newTopRight.push_back(bottomLeft.front() + (topRight.front() - bottomLeft.front()) / 2);
                newTopRight.push_back(topRight.back());
                newBottomLeft.push_back(newTopRight.front() + 1);
                newBottomLeft.push_back(bottomLeft.back());
                countShipsImpl(sea, newTopRight, bottomLeft, shipsCnt);
                countShipsImpl(sea, topRight, newBottomLeft, shipsCnt);
            }
        }
    }
}

int countShips(Sea sea, const vector<int> topRight, const vector<int> bottomLeft) {
    int shipsCnt = 0;
    countShipsImpl(sea, topRight, bottomLeft, shipsCnt);
    return shipsCnt;
}

#endif //ALGORITHMICCHALLENGES_SOLUTION_H
