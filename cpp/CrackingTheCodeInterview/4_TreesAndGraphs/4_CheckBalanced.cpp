#include "4_CheckBalanced.h"

namespace{

bool checkBalanced(const BstNodePtr& node, int& minHeight, int& maxHeight, int currentHeight){
    if (!node){
        if (minHeight == 0){
            minHeight = maxHeight = currentHeight;
            return true;
        }

        if (currentHeight < minHeight){
            minHeight = currentHeight;
        }

        if (currentHeight > maxHeight){
            maxHeight = currentHeight;
        }

        int heightDiff = maxHeight - minHeight;
        return heightDiff <= 1;
    }

    return checkBalanced(node->left_, minHeight, maxHeight, currentHeight + 1) &&
           checkBalanced(node->right_, minHeight, maxHeight, currentHeight + 1);
}

}

bool checkBalanced(const Bst& bst){
    if (!bst.head_)
        return true;
    int minHeight = 0, maxHeight = 0;
    return checkBalanced(bst.head_, minHeight, maxHeight, 0);
}
