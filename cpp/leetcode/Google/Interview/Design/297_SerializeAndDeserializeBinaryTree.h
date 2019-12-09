//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#ifndef ALGORITHMICCHALLENGES_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
#define ALGORITHMICCHALLENGES_297_SERIALIZEANDDESERIALIZEBINARYTREE_H

#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        ss << "[";
        vector<vector<TreeNode*>> nodeLevels;
        nodeLevels.push_back({root});
        while (any_of(begin(nodeLevels.back()), end(nodeLevels.back()),
            [](auto node) { return node != nullptr;})) {
            vector<TreeNode*> nextLevel;
            for (auto node : nodeLevels.back()) {
                if (node) {
                    nextLevel.push_back(node->left);
                    nextLevel.push_back(node->right);
                }
            }
            nodeLevels.push_back(move(nextLevel));
        }
        nodeLevels.pop_back();
        while (!nodeLevels.empty() && !nodeLevels.back().back())
            nodeLevels.back().pop_back();
        if (!nodeLevels.empty()) {
            auto levelIt = begin(nodeLevels);
            ss << levelIt->front()->val;
            ++levelIt;
            for (;levelIt != end(nodeLevels); ++levelIt) {
                for (auto node : *levelIt) {
                    ss << ",";
                    if (node)
                        ss << node->val;
                    else
                        ss << "null";
                }
            }
        }
        ss << "]";
        return ss.str();
    }

    static vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
            tokens.push_back(token);
        return tokens;
    }

    static TreeNode* createNode(const string& str){
        if (str[0] == 'n')
            return nullptr;
        return new TreeNode(stoi(str));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (data.length() == 2)
            return nullptr;
        string nodesStr = data.substr(1, data.length() - 2);
        auto nodeStrs = split(nodesStr, ',');
        auto nodeStrIt = begin(nodeStrs);
        auto head = new TreeNode(stoi(*nodeStrIt));
        if (++nodeStrIt == end(nodeStrs))
            return head;
        vector<TreeNode*> currentLevel{head};
        auto nodeIt = begin(currentLevel);
        vector<TreeNode*> nextLevel;
        for (;;) {
            //left
            if (((*nodeIt)->left = createNode(*nodeStrIt)))
                nextLevel.push_back((*nodeIt)->left);
            if (++nodeStrIt == end(nodeStrs))
                break;

            //right
            if (((*nodeIt)->right = createNode(*nodeStrIt)))
                nextLevel.push_back((*nodeIt)->right);
            if (++nodeStrIt == end(nodeStrs))
                break;

            //next
            if (++nodeIt == end(currentLevel)) {
                currentLevel = move(nextLevel);
                nextLevel.clear();
                nodeIt = begin(currentLevel);
            }
        }
        return head;
    }
};

#endif //ALGORITHMICCHALLENGES_297_SERIALIZEANDDESERIALIZEBINARYTREE_H
