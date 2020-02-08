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

inline constexpr size_t getAlphabetSize() { return 'z' - 'a' + 1; }
inline constexpr size_t getCharIndex(char c) { return c - 'a'; }
inline constexpr char getChar(size_t index) { return 'a' + index; }

struct Trie {
    Trie(size_t val) : val_{val} {}
    array<unique_ptr<Trie>, getAlphabetSize()> children_;
    vector<size_t> nextChars_;
    size_t val_ = 0;
};

void fillTrie(const vector<string> &words, Trie& trie) {
    for (const auto& word : words) {
        auto triePrefix = &trie;
        for (auto c : word) {
            size_t cI = getCharIndex(c);
            if (!triePrefix->children_[cI]) {
                triePrefix->children_[cI] = make_unique<Trie>(cI);
                triePrefix->nextChars_.push_back(cI);
            }
            triePrefix = triePrefix->children_[cI].get();
        }
    }
}

bool isDiagnoal(size_t row, size_t col) {
    return row == col;
}

bool isLastCell(
    size_t row, size_t col,
    size_t lastRow, size_t lastCol) {
    return row == lastRow && col == lastCol;
}

struct Cell {
    explicit Cell(Trie* row = nullptr, Trie* col = nullptr) : row_{row}, col_{col} {}
    Trie* row_;
    Trie* col_;
};

Cell getPrevColCell(
    size_t row, size_t col,
    const vector<vector<Cell>>& square) {
    return square[row][col - 1];
}

Cell getPrevRowCell(
    size_t row, size_t col,
    const vector<vector<Cell>>& square) {
    return square[row - 1][col];
}

void addSquare(const vector<vector<Cell>>& square,
               vector<vector<string>>& resSquares) {
    vector<string> wordSquare;
    wordSquare.reserve(square.size() - 1);
    for (size_t wordI = 1; wordI != square.size(); ++wordI) {
        string word;
        word.reserve(square.size() - 1);
        size_t wordRow = wordI, wordCol = wordI;
        for (size_t i = 1; i <= wordCol; ++i)
            word.push_back(getChar(square[wordRow][i].row_->val_));
        for (size_t i = wordRow + 1; i != square.size(); ++i)
            word.push_back(getChar(square[i][wordCol].row_->val_));
        wordSquare.push_back(move(word));
    }
    resSquares.push_back(move(wordSquare));
}

void fillCell(size_t row, size_t col,
              vector<vector<Cell>>& square,
              vector<vector<string>>& resSquares) {
    if (isDiagnoal(row, col)) {
        auto prevColCell = getPrevColCell(row, col, square);
        auto lastCell = isLastCell(row, col,
                                   square.size() - 1, square.front().size() - 1);
        for (auto nextChar : prevColCell.row_->nextChars_) {
            square[row][col].row_ = prevColCell.row_->children_[nextChar].get();
            square[row][col].col_ = prevColCell.row_->children_[nextChar].get();
            if (lastCell) {
                addSquare(square, resSquares);
            } else {
                fillCell(row + 1, 1, square, resSquares);
            }
        }
    } else {
        auto prevColCell = getPrevColCell(row, col, square);
        auto prevRowCell = getPrevRowCell(row, col, square);
        for (auto prevColNextChar : prevColCell.row_->nextChars_) {
            if (prevRowCell.col_->children_[prevColNextChar]) {
                square[row][col].row_ = prevColCell.row_->children_[prevColNextChar].get();
                square[row][col].col_ = prevRowCell.col_->children_[prevColNextChar].get();
                fillCell(row, col + 1, square, resSquares);
            }
        }
    }
}

vector<vector<string>> wordSquares(const vector<string> &words) {
    if (words.empty() || words.front().empty())
        return {};
    Trie trie {0};
    fillTrie(words, trie);
    vector<vector<Cell>> square(
        words.front().size() + 1,
        vector<Cell>(words.front().size() + 1));
    for (auto& row : square) {
        row[0].row_ = &trie;
        row[0].col_ = &trie;
    }
    square.front()[1].col_ = &trie;
    square.front()[1].row_ = &trie;
    vector<vector<string>> resSquares;
    fillCell(1, 1, square, resSquares);
    return resSquares;
}
}

#endif //ALGORITHMICCHALLENGES_425_WORDSQUARES_H
