//https://leetcode.com/problems/decode-string/
#ifndef ALGORITHMICCHALLENGES_394_DECODESTRING_H
#define ALGORITHMICCHALLENGES_394_DECODESTRING_H

#include <string>
#include <stack>

std::string decodeString(const std::string& s) {
    std::stack<int> numbers;
    int numberBegin = -1;
    std::stack<std::string> decoded;
    decoded.push("");
    for (std::size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9' && numberBegin == -1) {
            numberBegin = i;
        } else if (s[i] == '[') {
            numbers.push(std::stoi(s.substr(numberBegin, i - numberBegin)));
            numberBegin = -1;
            decoded.push("");
        } else if (s[i] == ']') {
            std::string decodedPart;
            decodedPart.reserve(decoded.top().size() * numbers.top());
            for (int j = 0; j < numbers.top(); ++j)
                decodedPart.append(decoded.top());
            decoded.pop();
            numbers.pop();
            decoded.top().append(decodedPart);
        } else if (numberBegin == -1) {
            decoded.top().append(std::string{s[i]});
        }
    }
    return decoded.top();
}

#endif //ALGORITHMICCHALLENGES_394_DECODESTRING_H
