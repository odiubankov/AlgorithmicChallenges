#include "11_RandomNode.h"
#include <gtest/gtest.h>
#include <random>
#include <unordered_set>
#include <chrono>

TEST(RandomNode, test) {
    BstRandom bst;
    for (int i = 0; i < 1000; ++i) {
        std::vector<int> values;
        values.reserve(100);
        for (int j = 0; j < 100; ++j)
            values.push_back(j);
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(begin(values), end(values), std::default_random_engine{seed});
        for (auto val : values)
            bst.insert(val);
        for (int j = 0; j < 100; ++j)
            ASSERT_TRUE(bst.find(j));
        std::unordered_set<int> removedItems;
        for (int j = 0; j < 100; ++j) {
            auto random = bst.getRandom();
            ASSERT_EQ(removedItems.find(random), end(removedItems));
            bst.remove(random);
            ASSERT_FALSE(bst.find(random));
            removedItems.insert(random);
        }
        ASSERT_EQ(removedItems.size(), 100);
    }
}
