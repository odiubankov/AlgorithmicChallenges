//https://leetcode.com/problems/word-squares/
#ifndef ALGORITHMICCHALLENGES_425_WORDSQUARES_H
#define ALGORITHMICCHALLENGES_425_WORDSQUARES_H

#include <vector>
#include <string>
#include <array>
#include <memory>
#include <unordered_set>
using namespace std;

namespace WordSquares {

constexpr size_t getAlphabetSize() { return 'z' - 'a' + 1; }
constexpr size_t getCharIndex(char c) { return c - 'a'; }
constexpr char getChar(size_t index) { return 'a' + index; }

struct Trie {
    array<shared_ptr<Trie>, getAlphabetSize()> children_;
    unordered_set<size_t> liveChildren_;
};

vector<string> getAllPostfixes(const Trie *trie) {
    if (trie->liveChildren_.empty())
        return {""};
    vector<string> res;
    for (auto child : trie->liveChildren_) {
        char c = getChar(child);
        for (const auto &childPostfix : getAllPostfixes(trie->children_[child].get())) {
            res.push_back(c + childPostfix);
        }
    }
    return res;
}

vector<vector<string>> wordSquaresImpl(const vector<string> &startsWith, const Trie &trie) {
    if (!startsWith.empty() && startsWith.size() == startsWith.front().size())
        return {startsWith};
    const Trie *prefix = &trie;
    string prefixStr;
    for (size_t i = 0; i < startsWith.size(); ++i) {
        auto nextChar = startsWith[i][startsWith.size()];
        auto index = getCharIndex(nextChar);
        if (!prefix->children_[index]) {
            prefix = nullptr;
            break;
        }
        else {
            prefixStr += nextChar;
            prefix = prefix->children_[index].get();
        }
    }
    vector<vector<string>> res;
    if (prefix) {
        for (const auto &postfix : getAllPostfixes(prefix)) {
            auto start = startsWith;
            start.push_back(prefixStr + postfix);
            auto wordRes = wordSquaresImpl(start, trie);
            copy(begin(wordRes), end(wordRes), back_inserter(res));
        }
    }
    return res;
}

vector<vector<string>> wordSquares(const vector<string> &words) {
    Trie trie;
    for (const auto& word : words) {
        Trie *current = &trie;
        for (auto c : word) {
            size_t cI = getCharIndex(c);
            if (!current->children_[cI]) {
                current->children_[cI] = make_shared<Trie>();
                current->liveChildren_.insert(cI);
            }
            current = current->children_[cI].get();
        }
    }
    return wordSquaresImpl({}, trie);
}
}

#endif //ALGORITHMICCHALLENGES_425_WORDSQUARES_H
