#ifndef ALGORITHMICCHALLENGES_DIRECTEDGRAPH_H
#define ALGORITHMICCHALLENGES_DIRECTEDGRAPH_H

#include <vector>

class Node;
using NodePtrT = std::shared_ptr<Node>;

class Node {
public:
    std::vector<NodePtrT> children_;
};

#endif //ALGORITHMICCHALLENGES_DIRECTEDGRAPH_H
