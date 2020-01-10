//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#ifndef ALGORITHMICCHALLENGES_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
#define ALGORITHMICCHALLENGES_297_SERIALIZEANDDESERIALIZEBINARYTREE_H

#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    static const string NULLNODE;
    static const char DELIMETER;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss, nullStream;
        queue<TreeNode*> nodesDFS;
        nodesDFS.push(root);
        do {
            auto node = nodesDFS.front();
            nodesDFS.pop();
            if (node) {
                ss << nullStream.str();
                nullStream.str("");
                nullStream.clear();
                if (ss.tellp() != 0)
                    ss << DELIMETER;
                ss << node->val;
                nodesDFS.push(node->left);
                nodesDFS.push(node->right);
            } else {
                nullStream << DELIMETER << NULLNODE;
            }
        } while (!nodesDFS.empty());
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (data.empty())
            return nullptr;
        string nodeStr;
        istringstream tokenStream(data);
        getline(tokenStream, nodeStr, DELIMETER);
        auto head = new TreeNode(stoi(nodeStr));
        queue<TreeNode*> nodes;
        nodes.push(head);
        while (getline(tokenStream, nodeStr, DELIMETER)) {
            if (nodeStr != NULLNODE) {
                nodes.front()->left = new TreeNode(stoi(nodeStr));
                nodes.push(nodes.front()->left);
            }

            if (getline(tokenStream, nodeStr, DELIMETER)) {
                if (nodeStr != NULLNODE) {
                    nodes.front()->right = new TreeNode(stoi(nodeStr));
                    nodes.push(nodes.front()->right);
                }
            }
            nodes.pop();
        }
        return head;
    }
};

string const Codec::NULLNODE = "null";
char const Codec::DELIMETER = ',';

#endif //ALGORITHMICCHALLENGES_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
