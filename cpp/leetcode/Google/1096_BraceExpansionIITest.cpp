#include "1096_BraceExpansionII.h"
#include <gtest/gtest.h>

TEST(BraceExpansionII, test1) {
    vector<string> res{"a","b","c"};
    ASSERT_EQ(res, braceExpansionII("{{a,b},{b,c}}"));
}

TEST(BraceExpansionII, test2) {
    vector<string> res{"a","b","c"};
    ASSERT_EQ(res, braceExpansionII("{a,b,c}"));
}

TEST(BraceExpansionII, test3) {
    vector<string> res{"ac","ad","bc","bd"};
    ASSERT_EQ(res, braceExpansionII("{a,b}{c,d}"));
}

TEST(BraceExpansionII, test4) {
    vector<string> res{"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"};
    ASSERT_EQ(res, braceExpansionII("a{b,c}{d,e}f{g,h}"));
}

TEST(BraceExpansionII, test5) {
    vector<string> res{"a","ab","ac","z"};
    ASSERT_EQ(res, braceExpansionII("{{a,z},a{b,c},{ab,z}}"));
}
