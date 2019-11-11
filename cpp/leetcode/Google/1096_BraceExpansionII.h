//https://leetcode.com/problems/brace-expansion-ii/
#ifndef ALGORITHMICCHALLENGES_1096_BRACEEXPANSIONII_H
#define ALGORITHMICCHALLENGES_1096_BRACEEXPANSIONII_H

#include <vector>
#include <string>
#include <memory>
#include <stack>
#include <set>
using namespace std;

using ResT = vector<string>;

ResT multiply(const ResT& first, const ResT& second) {
    ResT res;
    res.reserve(first.size() * second.size());
    for (const auto& f : first) {
        for (const auto& s : second) {
            res.push_back(f + s);
        }
    }
    return res;
}

size_t eval(ResT& res, const string& str, size_t pos) {
    string current;
    for (size_t i = pos; i < str.length(); ++i) {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
            current += c;
        else {
            if (!current.empty()) {
                if (!res.empty() && str[i - current.length() - 1] == '}') {
                    res = multiply(res, {current});
                } else {
                    res.push_back(move(current));
                }
                current.clear();
            }
            if (c == '}')
                return i;
            if (c == '{') {
                ResT next;
                char prev = str[i - 1];
                i = eval(next, str, i + 1);
                if (res.empty()) {
                    res = next;
                } else if (prev == ',') {
                    copy(begin(next), end(next), back_inserter(res));
                } else if (prev == '}') {
                    res = multiply(res, next);
                } else {
                    auto last = res.back();
                    res.pop_back();
                    auto toAdd = multiply({last}, next);
                    copy(begin(toAdd), end(toAdd), back_inserter(res));
                }
            }
        }
    }
    if (!current.empty())
        res.push_back(current);
    return str.size();
}

ResT braceExpansionII(const string& expression) {
    ResT res;
    eval(res, expression, 0);
    set<string> s(begin(res), end(res));
    res.assign( s.begin(), s.end() );
    return res;
}

#endif //ALGORITHMICCHALLENGES_1096_BRACEEXPANSIONII_H
