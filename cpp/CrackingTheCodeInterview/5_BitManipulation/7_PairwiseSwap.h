#ifndef ALGORITHMICCHALLENGES_7_PAIRWISESWAP_H
#define ALGORITHMICCHALLENGES_7_PAIRWISESWAP_H

#include <cstdint>

int pairwiseSwap(uint32_t val) {
    static const uint32_t OddMask = 0x55555555;
    static const uint32_t EvenMask = 0xAAAAAAAA;
    return (((val & OddMask) << 1) | ((val & EvenMask) >> 1));
}

#endif //ALGORITHMICCHALLENGES_7_PAIRWISESWAP_H
