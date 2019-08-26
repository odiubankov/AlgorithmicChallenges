//https://leetcode.com/problems/binary-tree-level-order-traversal
#ifndef ALGORITHMICCHALLENGES_3_LISTOFDEPTH_H
#define ALGORITHMICCHALLENGES_3_LISTOFDEPTH_H

#include <list>
#include <vector>

#include "DataStructures/BST.h"

using ListOfDepth = std::vector<std::vector<int>>;

ListOfDepth getListOfDepthRecursion(const Bst& bst);
ListOfDepth getListOfDepthIterative(const Bst& bst);

#endif //ALGORITHMICCHALLENGES_3_LISTOFDEPTH_H
