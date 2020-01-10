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
        for (const auto& postfixStr : getAllPostfixes(trie->children_[child].get())) {
            res.push_back(c + postfixStr);
        }
    }
    return res;
}

vector<vector<string>> getWordSquares(const vector<string>& words, const Trie &trie) {
    if (!words.empty() && words.size() == words.front().size())
        return {words};
    const Trie* triePrefix = &trie;
    string prefixStr;
    for (size_t i = 0; i < words.size(); ++i) {
        auto nextChar = words[i][words.size()];
        auto index = getCharIndex(nextChar);
        if (!triePrefix->children_[index]) {
            triePrefix = nullptr;
            break;
        }
        else {
            prefixStr += nextChar;
            triePrefix = triePrefix->children_[index].get();
        }
    }
    vector<vector<string>> res;
    if (triePrefix) {
        for (const auto &postfixStr : getAllPostfixes(triePrefix)) {
            auto nextWords = words;
            nextWords.push_back(prefixStr + postfixStr);
            auto wordRes = getWordSquares(nextWords, trie);
            copy(begin(wordRes), end(wordRes), back_inserter(res));
        }
    }
    return res;
}

void fillTrie(const vector<string> &words, Trie& trie) {
    for (const auto& word : words) {
        auto triePrefix = &trie;
        for (auto c : word) {
            size_t cI = getCharIndex(c);
            if (!triePrefix->children_[cI]) {
                triePrefix->children_[cI] = make_shared<Trie>();
                triePrefix->liveChildren_.insert(cI);
            }
            triePrefix = triePrefix->children_[cI].get();
        }
    }
}

vector<vector<string>> wordSquares(const vector<string> &words) {
    Trie trie;
    fillTrie(words, trie);
    return getWordSquares({}, trie);
}
}

#endif //ALGORITHMICCHALLENGES_425_WORDSQUARES_H
