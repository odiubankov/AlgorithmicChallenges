#include "394_DecodeString.h"
#include <gtest/gtest.h>

TEST(DecodeStr, test) {
    ASSERT_EQ("aaabcbc", decodeString("3[a]2[bc]"));
//    ASSERT_EQ("accaccacc", decodeString("3[a2[c]]"));
//    ASSERT_EQ("abcabccdcdcdef", decodeString("2[abc]3[cd]ef"));
}
