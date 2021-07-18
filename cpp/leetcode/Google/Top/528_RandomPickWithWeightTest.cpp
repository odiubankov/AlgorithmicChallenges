#include "528_RandomPickWithWeight.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(RandomPickWithWeight, test1) {
    SolutionWithItemsRemoval withRemoval{ {1} };
    ASSERT_EQ(withRemoval.randomPickWithWeight(), 0);
    ASSERT_EQ(withRemoval.randomPickWithWeight(), -1);
}

TEST(RandomPickWithWeight, test2) {
    SolutionWithItemsRemoval withRemoval{ {} };
    ASSERT_EQ(withRemoval.randomPickWithWeight(), -1);
}

TEST(RandomPickWithWeight, test3) {
    SolutionWithItemsRemoval withRemoval{ {50, 50} };
    vector<int> realCnt(2, 0);
    for (int i = 0; i < 100; ++i) {
        ++realCnt[withRemoval.randomPickWithWeight()];
    }

    ASSERT_EQ(withRemoval.randomPickWithWeight(), -1);

    for (int i = 0; i < realCnt.size(); ++i) {
        std::cout << " i=" << i << " cnt=" << realCnt[i] << std::endl;
    }

    ASSERT_TRUE(false);
}

TEST(RandomPickWithWeight, test4) {
    SolutionWithItemsRemoval withRemoval{ {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };
    vector<int> realCnt(10, 0);
    for (int i = 0; i < 100; ++i) {
        int index = withRemoval.randomPickWithWeight();
        ++realCnt[index];
    }

    ASSERT_EQ(withRemoval.randomPickWithWeight(), -1);

    for (int i = 0; i < realCnt.size(); ++i) {
        std::cout << " i=" << i << " cnt=" << realCnt[i] << std::endl;
    }

    ASSERT_TRUE(false);
}
