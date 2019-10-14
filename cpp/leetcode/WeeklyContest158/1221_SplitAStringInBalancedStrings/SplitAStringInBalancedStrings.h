#ifndef ALGORITHMICCHALLENGES_SPLITASTRINGINBALANCEDSTRINGS_H
#define ALGORITHMICCHALLENGES_SPLITASTRINGINBALANCEDSTRINGS_H

#include <string>
#include <stack>

class SolutionBS
{
public:
    int balancedStringSplit(std::string s)
    {
        if (s.empty() || s.size() % 2 != 0)
            return 0;

        int res = 0;
        std::stack<char> chrs;
        for (auto c : s) {
            if (chrs.empty() || c == chrs.top())
                chrs.push(c);
            else
                chrs.pop();
            if (chrs.empty())
                ++res;
        }
        return res;
    }
};

#endif //ALGORITHMICCHALLENGES_SPLITASTRINGINBALANCEDSTRINGS_H
