//https://leetcode.com/contest/biweekly-contest-11
#ifndef ALGORITHMICCHALLENGES_SOLUTION_H
#define ALGORITHMICCHALLENGES_SOLUTION_H
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

namespace contest18{


vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

}

vector<int> arrayRankTransform(vector<int>& arr) {
    if (arr.empty())
        return {};
    auto sortedArr = arr;
    sort(begin(sortedArr), end(sortedArr));
    unordered_map<int, int> valRanks;
    int rank = 1;
    valRanks[sortedArr.front()] = rank;
    auto itPrev = begin(sortedArr);
    for (auto it = itPrev + 1; it != end(sortedArr); ++it, ++itPrev) {
        if (*it != *itPrev)
            ++rank;
        valRanks[*it] = rank;
    }
    for (int& val : arr) {
        val = valRanks[val];
    }

    return arr;
}

string breakPalindrome(string palindrome) {
    if (palindrome.length() < 2)
        return "";
    auto nonAPos = find_if(begin(palindrome), end(palindrome), [](char c) { return c != 'a';  });
    if (palindrome.length() % 2 == 1 &&
        distance(begin(palindrome), nonAPos) == palindrome.length() / 2) {
        nonAPos = find_if(nonAPos + 1, end(palindrome), [](char c) { return c != 'a';  });
    }
    if (nonAPos == end(palindrome)) {
        palindrome.back() = 'b';
    } else {
        *nonAPos = 'a';
    }
    return palindrome;
}

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    if (mat.empty() || mat.front().empty())
        return mat;
    for (int j = (int)(mat.front().size()) - 1; j >=0; --j) {
        vector<int> diagonalElements{mat[0][j]};
        for (int i = 1; i < mat.size() && (j + i) < mat.front().size(); ++i) {
            diagonalElements.push_back(mat[i][j + i]);
        }
        sort(begin(diagonalElements), end(diagonalElements));
        mat[0][j] = diagonalElements.front();
        auto elIt = begin(diagonalElements) + 1;
        for (int i = 1; i < mat.size() && (j + i) < mat.front().size(); ++i) {
            mat[i][j + i] = *elIt;
            ++elIt;
        }
    }
    for (int i = 1; i < mat.size(); ++i) {
        vector<int> diagonalElements{mat[i][0]};
        for (int j = 1; j < mat.front().size() && (i + j) < mat.size(); ++j) {
            diagonalElements.push_back(mat[i + j][j]);
        }
        sort(begin(diagonalElements), end(diagonalElements));
        mat[i][0] = diagonalElements.front();
        auto elIt = begin(diagonalElements) + 1;
        for (int j = 1; j < mat.front().size() && (i + j) < mat.size(); ++j) {
            mat[i + j][j] = *elIt;
            ++elIt;
        }
    }
    return mat;
}

int maxValueAfterReverse(vector<int>& nums) {
    
}





#endif //ALGORITHMICCHALLENGES_SOLUTION_H
