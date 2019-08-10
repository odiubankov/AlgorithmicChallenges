#ifndef ALGORITHMICCHALLENGES_3_LISTOFDEPTH_H
#define ALGORITHMICCHALLENGES_3_LISTOFDEPTH_H

#include <list>
#include <vector>

#include "DataStructures/BST.h"

using ListOfDepth = std::vector<std::list<int>>;

ListOfDepth getListOfDepth(const Bst& bst);

#endif //ALGORITHMICCHALLENGES_3_LISTOFDEPTH_H
