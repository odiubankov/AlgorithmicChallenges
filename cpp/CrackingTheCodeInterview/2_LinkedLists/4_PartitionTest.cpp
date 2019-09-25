#include "4_Partition.h"
#include <gtest/gtest.h>

TEST(Partition, test) {
    auto head = createList({1, 4, 3, 2, 5, 2});

    head = partition(head, 3);

    std::vector<int> expectedVals {1, 2, 2, 4, 3, 5};
    auto runner = head;
    for (auto val : expectedVals) {
        ASSERT_TRUE(runner);
        ASSERT_EQ(runner->val, val);
        runner = runner->next;
    }

    ASSERT_FALSE(runner);

}
