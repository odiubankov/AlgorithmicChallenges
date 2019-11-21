#include "642_DesignSearchAutocompleteSystem.h"
#include <gtest/gtest.h>

TEST(AutocompleteSystem, test) {
    AutocompleteSystem as{{"i love you", "island","ironman", "i love leetcode"}, {5,3,2,2}};
    vector<string> res1{"i love you", "island", "i love leetcode"};
    ASSERT_EQ(res1, as.input('i'));
    vector<string> res2{"i love you", "i love leetcode"};
    ASSERT_EQ(res2, as.input(' '));
    ASSERT_TRUE(as.input('a').empty());
    ASSERT_TRUE(as.input('#').empty());
}

TEST(AutocompleteSystem, test2) {
    AutocompleteSystem as{{"i love you", "island","ironman", "i love leetcode"}, {5,3,2,2}};
    vector<string> res1{"i love you","island","i love leetcode"};
    ASSERT_EQ(res1, as.input('i'));
    vector<string> res2{"i love you","i love leetcode"};
    ASSERT_EQ(res2, as.input(' '));
    ASSERT_TRUE(as.input('a').empty());
    ASSERT_TRUE(as.input('#').empty());
    ASSERT_EQ(res1, as.input('i'));
    vector<string> res3{"i love you","i love leetcode","i a"};
    ASSERT_EQ(res3, as.input(' '));
    vector<string> res4{"i a"};
    ASSERT_EQ(res4, as.input('a'));
    ASSERT_TRUE(as.input('#').empty());
    vector<string> res5{"i love you","island","i a"};
    ASSERT_EQ(res5, as.input('i'));
    vector<string> res6{"i love you","i a","i love leetcode"};
    ASSERT_EQ(res6, as.input(' '));
    ASSERT_EQ(res4, as.input('a'));
}
