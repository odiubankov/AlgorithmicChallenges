#include "1_IsUnique.h"
#include "Utils/StringUtils.h"
#include <array>

bool isUnique(const std::string& str) {
    if (str.length() > static_cast<size_t>(strutils::getCharactersCnt<char>()))
        return false;

    std::array<bool, strutils::getCharactersCnt<char>()> charAvailable = {false};
    for (auto character : str) {
        auto index = strutils::getCharacterIndex(character);
        if (charAvailable[index])
            return false;
        charAvailable[index] = true;
    }

    return true;
}
