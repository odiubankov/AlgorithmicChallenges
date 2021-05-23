// https://leetcode.com/problems/group-anagrams/description/

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

#ifndef ALGORITHMICCHALLENGES_49_GROUPANAGRAMS_H
#define ALGORITHMICCHALLENGES_49_GROUPANAGRAMS_H

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    unordered_map<std::string, std::vector<std::string>> anagrams;
    for (const auto& str : strs) {
        vector<int> charsCnt('z' - 'a' + 1, 0);
        for (auto c : str)
            ++charsCnt[c - 'a'];
        std::stringstream ss;
        for (auto cnt : charsCnt)
            ss << cnt << "|";
        anagrams[ss.str()].push_back(str);
    }

    std::vector<std::vector<std::string>> groupedAnagrams;
    for (auto& a : anagrams)
        groupedAnagrams.push_back(move(a.second));
    return groupedAnagrams;
}

#endif //ALGORITHMICCHALLENGES_49_GROUPANAGRAMS_H
