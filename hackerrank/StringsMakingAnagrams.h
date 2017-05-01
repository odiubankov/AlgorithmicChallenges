#ifndef HACKERRANK_STRINGSMAKINGANAGRAMS_H
#define HACKERRANK_STRINGSMAKINGANAGRAMS_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

namespace makinganagrams
{
    int number_needed(string a, string b)
    {
        std::vector<int> characters('z' - 'a' + 1, 0);
        for (const auto& character : a)
        {
            ++characters[character - 'a'];
        }

        for (const auto& character : b)
        {
            --characters[character - 'a'];
        }

        int result = 0;
        for (const auto& diff : characters)
        {
            result += abs(diff);
        }

        return result;
    }
}

#endif //HACKERRANK_STRINGSMAKINGANAGRAMS_H
