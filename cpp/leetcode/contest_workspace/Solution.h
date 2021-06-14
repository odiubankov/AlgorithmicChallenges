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

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

using ServerT = array<int, 2>;
using AvailableServersT = priority_queue<ServerT, vector<ServerT>, greater<ServerT>>;
using TaskServersT = vector<int>;
using ServersAvilableAtSecT = map<int, vector<ServerT>>;
using TasksToAssignT = queue<int>;

vector<int> assignTasks(const vector<int>& servers, const vector<int>& tasks) {
    AvailableServersT availableServers;
    for (int index = 0; index != servers.size(); ++index) {
        availableServers.emplace(ServerT{servers[index], index});
    }

    TaskServersT taskServers;
    ServersAvilableAtSecT serversAvailableAtSec;
    TasksToAssignT tasksToAssign;
    for (int sec = 0; sec < tasks.size(); ++sec) {
        for (const auto& server : serversAvailableAtSec[sec]) {
            availableServers.emplace(server);
        }
        serversAvailableAtSec.erase(sec);

        tasksToAssign.push(tasks[sec]);

        while (!availableServers.empty() && !tasksToAssign.empty()) {
            taskServers.push_back(availableServers.top()[1]);
            serversAvailableAtSec[sec + tasksToAssign.front()].push_back(availableServers.top());
            availableServers.pop();
            tasksToAssign.pop();
        }
    }

    int currentSecond = 0;
    while (!tasksToAssign.empty()) {
        if (availableServers.empty()) {
            auto availableServersIt = begin(serversAvailableAtSec);
            currentSecond = availableServersIt->first;
            for (const auto& server : availableServersIt->second) {
                availableServers.emplace(server);
            }
            serversAvailableAtSec.erase(availableServersIt);
        }

        taskServers.push_back(availableServers.top()[1]);
        serversAvailableAtSec[currentSecond + tasksToAssign.front()].push_back(availableServers.top());
        availableServers.pop();
        tasksToAssign.pop();
    }

    return taskServers;
}

#endif //ALGORITHMICCHALLENGES_SOLUTION_H
