#include "425_WordSquares.h"
#include <gtest/gtest.h>

TEST(WordSquares, test) {
    ASSERT_EQ(2, WordSquares::wordSquares({"area","lead","wall","lady","ball"}).size());
}
