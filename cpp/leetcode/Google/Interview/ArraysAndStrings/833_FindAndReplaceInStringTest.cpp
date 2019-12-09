#include "833_FindAndReplaceInString.h"
#include <gtest/gtest.h>

TEST(FindAndReplace, test) {
    ASSERT_EQ("", findReplaceString("jjievdtjfb", {4,6,1}, {"md","tjgb","jf"}, {"foe","oov","e"}));
}