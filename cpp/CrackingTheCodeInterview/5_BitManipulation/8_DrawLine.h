#ifndef ALGORITHMICCHALLENGES_8_DRAWLINE_H
#define ALGORITHMICCHALLENGES_8_DRAWLINE_H

#include <vector>

void drawLine(std::vector<unsigned char>& screen, int width, int x1, int x2, int y) {
    auto lineIndex = (y * width) / 8;
    auto firstCharIndex = x1 / 8;
    unsigned char mask = 1;
    int leftIndent = x1 - firstCharIndex * 8;
    for (int i = 1; i < (8 - leftIndent); ++i)
        mask = ((mask << 1u) | 1u);
    screen[lineIndex + firstCharIndex] |= mask;

    auto lastCharIndex = x2 / 8;
    mask = 1;
    leftIndent = x2 - lastCharIndex * 8;
    for (int i = 1; i < (8 - leftIndent); ++i)
        mask = ((mask << 1u) | 1u);
    mask = ~mask;
    screen[lineIndex + lastCharIndex] |= mask;
    for (auto i = firstCharIndex + 1; i < lastCharIndex; ++i)
        screen[lineIndex + i] = 0xFF;
}

#endif //ALGORITHMICCHALLENGES_8_DRAWLINE_H
