//https://leetcode.com/problems/word-search-ii/
#ifndef ALGORITHMICCHALLENGES_212_WORDSEARCHII_H
#define ALGORITHMICCHALLENGES_212_WORDSEARCHII_H

#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include <memory>

using namespace std;

constexpr size_t getAlphabetSize() { return 'z' - 'a' + 1; }
constexpr size_t getCharIndex(char c) { return c - 'a'; }

class SolutionFindWords {
public:
    struct Trie {
        std::array<unique_ptr<Trie>, getAlphabetSize()> children_;
        bool finish_ = false;
    };

    static unique_ptr<Trie> fillTrie(const vector<string>& words) {
        auto trie = make_unique<Trie>();
        for (const auto& word : words) {
            auto current = trie.get();
            for (auto c : word) {
                size_t cI = getCharIndex(c);
                if (!current->children_[cI])
                    current->children_[cI] = make_unique<Trie>();
                current = current->children_[cI].get();
            }
            current->finish_ = true;
        }
        return trie;
    }

    using BoardWordsT = unordered_set<string>;

    void findWordsWithPrefix2(
            vector<vector<char>>& board,
            int i, int j,
            Trie* trie,
            BoardWordsT& boardWords,
            string word) {
        if (i == -1 || j == -1 || i == board.size() || j == board.front().size() || board[i][j] == '*')
            return;
        auto character = board[i][j];
        word += character;
        auto charIndex = getCharIndex(character);
        if (trie->children_[charIndex]) {
            trie = trie->children_[charIndex].get();
        } else {
            return;
        }
        if (trie->finish_)
            boardWords.insert(word);
        board[i][j] = '*';
        findWordsWithPrefix2(board, i + 1, j, trie, boardWords, word);
        findWordsWithPrefix2(board, i - 1, j, trie, boardWords, word);
        findWordsWithPrefix2(board, i, j + 1, trie, boardWords, word);
        findWordsWithPrefix2(board, i, j - 1, trie, boardWords, word);
        board[i][j] = character;
    }

    vector<string> findWordsSimple(vector<vector<char>>& board, const vector<string>& words) {
        if (board.empty() || board.front().empty())
            return {};

        auto trie = fillTrie(words);
        BoardWordsT boardWords;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board.front().size(); ++j) {
                findWordsWithPrefix2(board, i, j, trie.get(), boardWords, "");
            }
        }
        return {begin(boardWords), end(boardWords)};
    }
};

#endif //ALGORITHMICCHALLENGES_212_WORDSEARCHII_H
