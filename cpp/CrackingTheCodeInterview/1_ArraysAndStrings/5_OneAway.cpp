#include "5_OneAway.h"
#include <cstdlib>

bool isOneAway(const std::string& a, const std::string& b) {
    if (std::abs(static_cast<int>(a.length()) - static_cast<int>(b.length())) > 1)
        return false;

    bool diffFound = false;
    auto aIt = cbegin(a);
    auto bIt = cbegin(b);
    for (; aIt != cend(a) && bIt != cend(b);) {
        if (*aIt != *bIt) {
            if (diffFound)
                return false;
            else
                diffFound = true;
            if (a.length() > b.length()) {
                ++aIt;
            } else if (b.length() > a.length()) {
                ++bIt;
            } else {
                ++aIt;
                ++bIt;
            }
        } else {
            ++aIt;
            ++bIt;
        }
    }

    //check the last character
    if (diffFound && (aIt != cend(a) || bIt != cend(b)))
        return false;

    return true;
}
