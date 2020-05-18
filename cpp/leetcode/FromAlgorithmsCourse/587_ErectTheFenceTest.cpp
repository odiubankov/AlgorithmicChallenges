#include "587_ErectTheFenceTest.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

TEST(ErectTheFence, test) {
    vector<Tree> trees{Tree{1, 1}, Tree{2, 2}, Tree{2, 0}, Tree{2, 4}, Tree{3, 3}, Tree{4, 2}};
    auto res = outerTrees(trees);
    ASSERT_TRUE(std::find(begin(res), end(res), Tree{2, 0}) != end(res));
    ASSERT_TRUE(std::find(begin(res), end(res), Tree{1, 1}) != end(res));
    ASSERT_TRUE(std::find(begin(res), end(res), Tree{2, 4}) != end(res));
    ASSERT_TRUE(std::find(begin(res), end(res), Tree{4, 2}) != end(res));
    ASSERT_TRUE(std::find(begin(res), end(res), Tree{3, 3}) != end(res));
}

TEST(ErectTheFence, test2) {
    vector<Tree> trees{Tree{0, 0}, Tree{0, 100}, Tree{100, 100}, Tree{100, 0}, Tree{50, 50}};
    auto res = outerTrees(trees);
    ASSERT_EQ(res.size(), 4);
}

TEST(ErectTheFence, test3) {
    vector<Tree> trees{Tree{3, 3}, Tree{2, 4}, Tree{2, 2}, Tree{7, 4}, Tree{3, 4}};
    auto res = outerTrees(trees);
    ASSERT_EQ(res.size(), 4);
}

TEST(ErectTheFence, test4) {
    vector<Tree> trees{Tree{0, 2}, Tree{1, 1}, Tree{2, 2}, Tree{2, 4}, Tree{4, 2}, Tree{3, 3}};
    auto res = outerTrees(trees);
    ASSERT_EQ(res.size(), 5);
}

TEST(ErectTheFence, test5) {
    vector<Tree> trees{
        Tree{3, 0},
        Tree{4, 0},
        Tree{5, 0},
        Tree{6, 1},
        Tree{7, 2},
        Tree{7, 3},
        Tree{7, 4},
        Tree{6, 5},
        Tree{5, 5},
        Tree{4, 5},
        Tree{3, 5},
        Tree{2, 5},
        Tree{1, 4},
        Tree{1, 3},
        Tree{1, 2},
        Tree{2, 1},
        Tree{4, 2},
        Tree{0, 3},
    };
    auto res = outerTrees(trees);
    ASSERT_EQ(res.size(), 16);
}
