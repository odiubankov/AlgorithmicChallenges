//https://leetcode.com/problems/isomorphic-strings/
#ifndef ALGORITHMICCHALLENGES_205_ISOMORPHICSTRINGS_H
#define ALGORITHMICCHALLENGES_205_ISOMORPHICSTRINGS_H

#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(const string& s, const string& t) {
    unordered_map<char, char> mapping, backMapping;
    for (size_t i = 0; i < s.length(); ++i) {
        auto charIt = mapping.find(s[i]);
        if (charIt == end(mapping)) {
            if (backMapping.find(t[i]) != end(backMapping))
                return false;
            mapping[s[i]] = t[i];
            backMapping[t[i]] = s[i];
        } else if (charIt->second != t[i])
            return false;
    }
    return true;
}

#endif //ALGORITHMICCHALLENGES_205_ISOMORPHICSTRINGS_H
