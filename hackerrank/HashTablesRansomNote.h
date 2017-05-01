#ifndef LEETCODESOLUTIONS_HASHTABLESRANSOMNOTE_H
#define LEETCODESOLUTIONS_HASHTABLESRANSOMNOTE_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

namespace hackerrank
{

    bool ransom_note(vector<string> magazine, vector<string> ransom)
    {
        unordered_map<string, unsigned> magazineWords;
        for (const auto& word: magazine)
        {
            auto insertRes = magazineWords.emplace(word, 1);
            if (!insertRes.second)
            {
                ++(insertRes.first->second);
            }
        }

        for (const auto& word : ransom)
        {
            auto magazineIt = magazineWords.find(word);
            if (magazineIt == end(magazineWords) || magazineIt->second == 0)
                return false;
            --(magazineIt->second);
        }

        return true;
    }

}//namespace hackerrank

#endif //LEETCODESOLUTIONS_HASHTABLESRANSOMNOTE_H
