#include "2_CheckPermutation.h"

#include <array>
#include <limits>

int getCharacterIndex(char character) {
    return character - std::numeric_limits<char>::min();
}

bool checkPermutation(const std::string& a, const std::string& b) {
    if (a.size() != b.size())
        return false;

    std::array<int, std::numeric_limits<char>::max() - std::numeric_limits<char>::min()> charactersCnt{};
    for (auto character : a)
        ++charactersCnt[getCharacterIndex(character)];
    for (auto character : b) {
        if (--charactersCnt[getCharacterIndex(character)] < 0)
            return false;
    }

    return true;
}