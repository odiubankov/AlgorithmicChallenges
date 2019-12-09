//https://leetcode.com/problems/word-search-ii/
#ifndef ALGORITHMICCHALLENGES_212_WORDSEARCHII_H
#define ALGORITHMICCHALLENGES_212_WORDSEARCHII_H

#include <vector>
#include <string>
#include <array>
#include <unordered_set>
using namespace std;

constexpr size_t getAlphabetSize() { return 'z' - 'a' + 1; }
constexpr size_t getCharIndex(char c) { return c - 'a'; }

class SolutionFindWords {
public:
    struct Trie {
        std::array<shared_ptr<Trie>, getAlphabetSize()> children_;
        bool finish_ = false;
    };

    using BoardT = vector<vector<char>>;
    using VisitedT = vector<vector<char>>;

    struct BoardSearchCtx {
    private:
        const BoardT& board_;
        VisitedT visited_;
        int row_;
        int col_;

    public:
        BoardSearchCtx(const BoardT& board, VisitedT& visited, int row, int col)
            : board_{board}
            , visited_{visited}
            , row_{row}
            , col_{col} {
        }

        vector<BoardSearchCtx> getNeighbours() {
            vector<BoardSearchCtx> neighbours;
            int prevRow = row_ - 1, nextRow = row_ + 1, prevCol = col_ - 1, nextCol = col_ + 1;
            if (prevRow >= 0 && visited_[prevRow][col_] == 0)
                neighbours.emplace_back(board_, visited_, prevRow, col_);
            if (nextRow < board_.size() && visited_[nextRow][col_] == 0)
                neighbours.emplace_back(board_, visited_, nextRow, col_);
            if (nextCol < board_[row_].size() && visited_[row_][nextCol] == 0)
                neighbours.emplace_back(board_, visited_, row_, nextCol);
            if (prevCol >= 0 && visited_[row_][prevCol] == 0)
                neighbours.emplace_back(board_, visited_, row_, prevCol);
            return neighbours;
        }

        void markVisited() { visited_[row_][col_] = 1; }
        void unmarkVisited() { visited_[row_][col_] = 0; }
        char getChar() const { return board_[row_][col_]; }
    };

    vector<string> findBoardWordsWithPrefix(const Trie& prefix, BoardSearchCtx& boardCtx, string word) {
        vector<string> boardWords;
        if (prefix.finish_)
            boardWords.push_back(word);
        boardCtx.markVisited();
        for (auto& ctx : boardCtx.getNeighbours()) {
            if (auto nextCharTrie = prefix.children_[getCharIndex(ctx.getChar())]) {
                auto nextWords = findBoardWordsWithPrefix(*nextCharTrie, ctx, word + ctx.getChar());
                copy(begin(nextWords), end(nextWords), back_inserter(boardWords));
            }
        }
        boardCtx.unmarkVisited();
        return boardWords;
    }

    vector<string> findWords(const vector<vector<char>>& board, const vector<string>& words) {
        if (board.empty() || board.front().empty())
            return {};
        Trie dictionary;
        for (const auto& word : words) {
            Trie* current = &dictionary;
            for (auto c : word) {
                size_t cI = getCharIndex(c);
                if (!current->children_[cI])
                    current->children_[cI] = make_shared<Trie>();
                current = current->children_[cI].get();
            }
            current->finish_ = true;
        }

        unordered_set<string> boardWords;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (auto prefix = dictionary.children_[getCharIndex(board[i][j])]) {
                    vector<vector<char>> visited(board.size(), vector<char>(board[i].size(), 0));
                    BoardSearchCtx ctx{board, visited, i, j};
                    for (const auto& wordWithPrefix : findBoardWordsWithPrefix(*prefix, ctx, {ctx.getChar()}))
                        boardWords.insert(wordWithPrefix);
                }
            }
        }

        return {begin(boardWords), end(boardWords)};
    }
};

#endif //ALGORITHMICCHALLENGES_212_WORDSEARCHII_H
