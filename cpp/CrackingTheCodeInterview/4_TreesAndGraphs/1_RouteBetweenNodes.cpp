#include "1_RouteBetweenNodes.h"
#include <algorithm>

bool updateNextNodes(std::vector<NodePtrT>& nextNodes, const NodePtrT& nodeToFind) {
    std::vector<NodePtrT> childrenNodes;
    for (const auto& node : nextNodes) {
        if (node == nodeToFind)
            return true;
        std::copy(begin(node->children_), end(node->children_), std::back_inserter(childrenNodes));
    }

    nextNodes = std::move(childrenNodes);
    return false;
}

bool routeBetweenNodes(const NodePtrT& a, const NodePtrT& b) {
    std::vector<NodePtrT> aNextNodes {a}, bNextNodes {b};
    while (!aNextNodes.empty() || !bNextNodes.empty()) {
        if (updateNextNodes(aNextNodes, b) ||
            updateNextNodes(bNextNodes, a))
            return true;
    }

    return false;
}
