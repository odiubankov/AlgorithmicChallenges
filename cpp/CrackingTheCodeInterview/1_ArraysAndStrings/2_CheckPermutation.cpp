#include "2_CheckPermutation.h"
#include "Utils/StringUtils.h"

#include <array>


bool checkPermutation(const std::string& a, const std::string& b) {
    if (a.size() != b.size())
        return false;

    std::array<int, strutils::getCharactersCnt<char>()> charactersCnt{};
    for (auto character : a)
        ++charactersCnt[strutils::getCharacterIndex(character)];
    for (auto character : b) {
        if (--charactersCnt[strutils::getCharacterIndex(character)] < 0)
            return false;
    }

    return true;
}