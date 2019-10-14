#include "8_DrawLine.h"
#include <gtest/gtest.h>

TEST(DrawLine, test) {
    std::vector<unsigned char> screen(16, 0);
    drawLine(screen, 32, 10, 25, 3);
    unsigned char firstCharPixels = 0b00111111;
    unsigned char lastCharPixels = 0b10000000;
    std::size_t firstCharIndex = 12 + 1;
    std::size_t lastCharIndex = 12 + 3;
    ASSERT_EQ(screen[firstCharIndex], firstCharPixels);
    ASSERT_EQ(screen[lastCharIndex], lastCharPixels);
}
