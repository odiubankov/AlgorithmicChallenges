#ifndef ALGORITHMICCHALLENGES_STRINGUTILS_H
#define ALGORITHMICCHALLENGES_STRINGUTILS_H

#include <limits>

namespace strutils {

template<typename T>
constexpr int getCharactersCnt() noexcept {
    return std::numeric_limits<char>::max() - std::numeric_limits<char>::min() + 1;
}

template<typename T>
int getCharacterIndex(T character) {
    return character - std::numeric_limits<T>::min();
}

}

#endif //ALGORITHMICCHALLENGES_STRINGUTILS_H
