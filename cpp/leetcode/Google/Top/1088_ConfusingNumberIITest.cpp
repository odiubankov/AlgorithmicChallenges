#include "1088_ConfusingNumberII.h"
#include <gtest/gtest.h>

TEST(ConfusingNumber, test) {
    ASSERT_EQ(6, confusingNumberII(20));
}

TEST(ConfusingNumber, test2) {
    ASSERT_EQ(19, confusingNumberII(100));
}

TEST(ConfusingNumber, test3) {
    ASSERT_EQ(37, confusingNumberII(195));
}

TEST(ConfusingNumber, test4) {
    ASSERT_EQ(15411, confusingNumberII(999959));
}