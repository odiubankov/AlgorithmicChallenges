/*
* BFS: Shortest Reach in a Graph
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef HACKERRANK_SHORTESTREACHINGRAPH_H
#define HACKERRANK_SHORTESTREACHINGRAPH_H

#include <vector>
#include <queue>

namespace hackerrank
{

class Graph
{
    std::vector<std::vector<int>> _nodes;

public:
    Graph(int n)
        : _nodes(n)
    {
    }

    void add_edge(int u, int v)
    {
        _nodes[u].push_back(v);
        _nodes[v].push_back(u);
    }

    std::vector<int> shortest_reach(int start)
    {
        std::vector<bool> _visited(_nodes.size(), false);
        std::queue<std::pair<int, int>> toVisit;
        toVisit.emplace(start, 0);
        std::vector<int> distances(_nodes.size(), -1);
        while (!toVisit.empty()) {
            auto node = toVisit.front();
            if (_visited[node.first]) {
                toVisit.pop();
                continue;
            }

            _visited[node.first] = true;
            distances[node.first] = node.second;
            for (auto connectedNode : _nodes[node.first]) {
                toVisit.emplace(connectedNode, node.second + 6);
            }

            toVisit.pop();
        }

        return distances;
    }
};

}//namespace hackerrank

#endif //HACKERRANK_SHORTESTREACHINGRAPH_H
