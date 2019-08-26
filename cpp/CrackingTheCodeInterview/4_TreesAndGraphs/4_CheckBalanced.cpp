#include "4_CheckBalanced.h"

#include <queue>
#include <vector>

namespace {

bool checkBalanced(const BstNodePtr& node, int& currentHeight) {
    if (!node)
        return true;

    int leftHeight = currentHeight + 1;
    if (!checkBalanced(node->left_, leftHeight))
        return false;

    int rightHeight = currentHeight + 1;
    if (!checkBalanced(node->right_, rightHeight))
        return false;

    currentHeight = std::max(leftHeight, rightHeight);
    return abs(leftHeight - rightHeight) <= 1;
}

}

bool checkBalanced(const Bst& bst) {
    int currentHeight = 0;
    return checkBalanced(bst.head_, currentHeight);
}
