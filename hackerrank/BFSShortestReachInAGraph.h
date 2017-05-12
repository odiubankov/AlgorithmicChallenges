#ifndef LEETCODESOLUTIONS_SHORTESTREACHINGRAPH_H
#define LEETCODESOLUTIONS_SHORTESTREACHINGRAPH_H

#include <vector>
#include <queue>

using namespace std;

namespace hackerrank
{
  class Graph {
    vector<vector<int>> _nodes;

  public:
    Graph(int n)
      : _nodes(n){
    }

    void add_edge(int u, int v) {
      _nodes[u].push_back(v);
      _nodes[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
      vector<bool> _visited(_nodes.size(), false);
      queue<pair<int,int>> toVisit;
      toVisit.emplace(start, 0);
      vector<int> distances(_nodes.size(), -1);
      while (!toVisit.empty())
      {
        auto node = toVisit.front();
        if (_visited[node.first])
        {
          toVisit.pop();
          continue;
        }

        _visited[node.first] = true;
        distances[node.first] = node.second;
        for (auto connectedNode : _nodes[node.first])
        {
          toVisit.emplace(connectedNode, node.second + 6);
        }

        toVisit.pop();
      }

      return distances;
    }
  };
}

#endif //LEETCODESOLUTIONS_SHORTESTREACHINGRAPH_H
