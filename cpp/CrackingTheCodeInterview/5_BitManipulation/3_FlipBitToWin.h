#ifndef ALGORITHMICCHALLENGES_3_FLIPBITTOWIN_H
#define ALGORITHMICCHALLENGES_3_FLIPBITTOWIN_H
#include <cstdint>
#include <algorithm>

int flipBitToWin(uint32_t val) {
    int maxSequence = 0;
    int lastFlippedIndex = -1;
    int currentSequenceLength = 0;
    for (int i = 0; i < 32; ++i) {
        if (val & (1 << i))
            ++currentSequenceLength;
        else {
            if (lastFlippedIndex == -1) {
                ++currentSequenceLength;
            } else {
                maxSequence = std::max(maxSequence, currentSequenceLength);
                currentSequenceLength = (i - lastFlippedIndex);
            }

            lastFlippedIndex = i;
        }
    }

    return maxSequence;
}

#endif //ALGORITHMICCHALLENGES_3_FLIPBITTOWIN_H
