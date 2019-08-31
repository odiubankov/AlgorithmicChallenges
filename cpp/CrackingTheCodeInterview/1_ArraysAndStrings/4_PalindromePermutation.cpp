#include "4_PalindromePermutation.h"
#include "Utils/StringUtils.h"

#include <array>


bool isPalindromePermutation(const std::string& s) {
    std::array<int, strutils::getCharactersCnt<char>()> charactersCnt{};
    for (auto character : s)
        ++charactersCnt[strutils::getCharacterIndex(character)];
    bool oddFound = false;
    for (auto cnt : charactersCnt) {
        if (cnt % 2 != 0) {
            if (oddFound)
                return false;
            oddFound = true;
        }
    }

    return true;
}
