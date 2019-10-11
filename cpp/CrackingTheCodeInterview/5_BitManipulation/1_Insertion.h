#ifndef ALGORITHMICCHALLENGES_1_INSERTION_H
#define ALGORITHMICCHALLENGES_1_INSERTION_H

#include <cstdint>

void insertBits(uint32_t& N, uint32_t M, unsigned i, unsigned j) {
    if (M == 0)
        return;
    N &= (~(((1u << (j - i + 2u)) - 1u) << i));
    N |= (M << i);
}

#endif //ALGORITHMICCHALLENGES_1_INSERTION_H
