#include "6_StringCompression.h"
#include <cmath>

namespace {

int getCompressedLength(const std::string& str) {
    int compressedLength = 0;
    auto strIter = cbegin(str);
    auto prevCharacter = *strIter;
    ++strIter;
    int charsCnt = 1;
    for (; strIter != cend(str); ++strIter) {
        if (*strIter != prevCharacter) {
            compressedLength += static_cast<int>(log10(charsCnt) + 2);
            prevCharacter = *strIter;
            charsCnt = 1;
        } else {
            ++charsCnt;
        }
    }

    return compressedLength + static_cast<int>(log10(charsCnt)) + 2;
}

void addCharacter(std::string& compressedStr, char character, int cnt) {
    compressedStr += character;
    compressedStr += std::to_string(cnt);
}

}

std::string compressString(const std::string& str) {
    if (str.size() < 3)
        return str;

    auto newLength = getCompressedLength(str);
    if (newLength >= static_cast<int>(str.length()))
        return str;

    std::string compressedStr;
    compressedStr.reserve(newLength);
    auto strIter = cbegin(str);
    auto prevCharacter = *strIter;
    ++strIter;
    int charsCnt = 1;
    for (; strIter != cend(str); ++strIter) {
        if (*strIter != prevCharacter) {
            addCharacter(compressedStr, prevCharacter, charsCnt);
            prevCharacter = *strIter;
            charsCnt = 1;
        } else {
            ++charsCnt;
        }
    }

    addCharacter(compressedStr, prevCharacter, charsCnt);
    return compressedStr;
}
