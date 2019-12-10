//https://leetcode.com/problems/stream-of-characters/
#ifndef ALGORITHMICCHALLENGES_1032_STREAMOFCHARACTERS_H
#define ALGORITHMICCHALLENGES_1032_STREAMOFCHARACTERS_H

#include <vector>
#include <string>
#include <memory>
#include <array>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

constexpr size_t getAlphabetSize() { return 'z' - 'a' + 1; }
constexpr size_t getCharIndex(char c) { return c - 'a'; }

class StreamChecker {
public:
    struct Trie {
        std::array<shared_ptr<Trie>, getAlphabetSize()> children_;
        bool finish_ = false;
    }trie_;

    StreamChecker(const vector<string>& words) {
        for (auto word : words) {
            Trie* current = &trie_;
            for (auto c : word) {
                size_t cI = getCharIndex(c);
                if (!current->children_[cI])
                    current->children_[cI] = make_shared<Trie>();
                current = current->children_[cI].get();
            }
            current->finish_ = true;
        }
    }

    bool query(char letter) {
        size_t cI = getCharIndex(letter);
        for (auto wIt = begin(words_); wIt != end(words_);) {
            if ((*wIt)->children_[cI]) {
                *wIt = (*wIt)->children_[cI].get();
                ++wIt;
            } else {
                wIt = words_.erase(wIt);
            }
        }
        if (trie_.children_[cI])
            words_.push_back(trie_.children_[cI].get());
        return any_of(begin(words_), end(words_), [](auto word){ return word->finish_; });
    }

    list<Trie*> words_;
};

#endif //ALGORITHMICCHALLENGES_1032_STREAMOFCHARACTERS_H
