#ifndef LEETCODESOLUTIONS_TREESISTHISABINARYSEARCHTREE_H
#define LEETCODESOLUTIONS_TREESISTHISABINARYSEARCHTREE_H


namespace hackerrank
{
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    bool checkChildNode(Node* root, int leftBorder, int rightBorder)
    {
        if (root->data < leftBorder || root->data > rightBorder)
            return false;

        return (root->left == nullptr || checkChildNode(root->left, leftBorder, root->data - 1)) &&
            (root->right == nullptr || checkChildNode(root->right, root->data + 1, rightBorder));
    }

    bool checkBST(Node* root) {
        return (root->left == nullptr || checkChildNode(root->left, -2147483648, root->data - 1)) &&
               (root->right == nullptr || checkChildNode(root->right, root->data + 1, 2147483647));

    }
}

#endif //LEETCODESOLUTIONS_TREESISTHISABINARYSEARCHTREE_H
