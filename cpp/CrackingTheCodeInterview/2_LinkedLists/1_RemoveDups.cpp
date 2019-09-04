#include "1_RemoveDups.h"
#include <unordered_set>

void removeDups(std::list<int>& l) {
    std::unordered_set<int> vals;
    for (auto lIt = begin(l); lIt != end(l);) {
        if (vals.find(*lIt) != end(vals)) {
            lIt = l.erase(lIt);
        } else {
            vals.insert(*lIt);
            ++lIt;
        }
    }
}

void removeDupsNoExtraMemory(std::list<int>& l) {
    for (auto lIt = begin(l); lIt != end(l); ++lIt) {
        auto runnerIt = lIt;
        ++runnerIt;
        for (; runnerIt != end(l);) {
            if (*runnerIt == *lIt) {
                runnerIt = l.erase(runnerIt);
            } else {
                ++runnerIt;
            }
        }
    }
}
