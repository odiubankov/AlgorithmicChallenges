//https://leetcode.com/problems/encode-and-decode-strings/
#ifndef ALGORITHMICCHALLENGES_271_ENCODEANDDECODESTRINGS_H
#define ALGORITHMICCHALLENGES_271_ENCODEANDDECODESTRINGS_H

#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(const vector<string>& strs) {
        stringstream ss;
        for (auto& str : strs)
            ss << str.length() << "|" << str;
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t pos = 0;
        while (pos < s.length()) {
            size_t lengthSeparator = s.find('|', pos);
            string lengthStr = s.substr(pos, lengthSeparator - pos);
            size_t length = stoi(lengthStr);
            pos = lengthSeparator + 1;
            strs.push_back(s.substr(pos, length));
            pos += length;
        }
        return strs;
    }
};

#endif //ALGORITHMICCHALLENGES_271_ENCODEANDDECODESTRINGS_H
