#include "688_KnightProbabilityChessboard.h"
#include <gtest/gtest.h>

TEST(KnightProb, test) {
    ASSERT_TRUE((knightProbability(3, 2, 0, 0) - 0.06250) < 0.00001);
}