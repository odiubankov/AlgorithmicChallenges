/**
* Trees: Is This a Binary Search Tree?
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

#ifndef HACKERRANK_TREESISTHISABINARYSEARCHTREE_H
#define HACKERRANK_TREESISTHISABINARYSEARCHTREE_H

namespace hackerrank
{

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool checkChildNode(Node *root, int leftBorder, int rightBorder)
{
    return !(root->data < leftBorder || root->data > rightBorder)
        && (root->left == nullptr || checkChildNode(root->left, leftBorder, root->data - 1)) &&
    (root->right == nullptr || checkChildNode(root->right, root->data + 1, rightBorder));

}

bool checkBST(Node *root)
{
    return (root->left == nullptr || checkChildNode(root->left, -2147483648, root->data - 1)) &&
        (root->right == nullptr || checkChildNode(root->right, root->data + 1, 2147483647));

}

}//namespace hackerrank

#endif //HACKERRANK_TREESISTHISABINARYSEARCHTREE_H
