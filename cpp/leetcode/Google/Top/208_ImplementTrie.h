//https://leetcode.com/problems/implement-trie-prefix-tree/
#ifndef ALGORITHMICCHALLENGES_208_IMPLEMENTTRIE_H
#define ALGORITHMICCHALLENGES_208_IMPLEMENTTRIE_H

#include <string>
#include <memory>
#include <array>
using namespace std;

constexpr size_t getAlphabetSize() {
    return 'z' - 'a' + 1;
}

constexpr size_t getCharIndex(char c) {
    return c - 'a';
}

class Trie {
public:
    struct Node {
        bool finish_ = false;
        array<shared_ptr<Node>, getAlphabetSize()> children_;
    }root_;

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        Node* current = &root_;
        for (char c : word) {
            size_t i = getCharIndex(c);
            if (!current->children_[i])
                current->children_[i] = make_shared<Node>();
            current = current->children_[i].get();
        }
        current->finish_ = true;
    }

     const Node* getPrefixNode(const string& word) const {
        auto current = &root_;
        for (char c : word) {
            size_t i = getCharIndex(c);
            if (!current->children_[i])
                return nullptr;
            current = current->children_[i].get();
        }
        return current;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        auto node = getPrefixNode(word);
        return node && node->finish_;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        return getPrefixNode(prefix);
    }
};

#endif //ALGORITHMICCHALLENGES_208_IMPLEMENTTRIE_H
