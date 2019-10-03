#include "3_URLify.h"

std::string urlify(const std::string& str) {
    auto spaceCnt = std::count(begin(str), end(str), ' ');
    auto newLength = str.length() + 2 * spaceCnt;
    std::string result;
    result.reserve(newLength);
    for (auto character : str)
        result += character == ' ' ? "%20" : std::string(1, character);

    return result;
}
