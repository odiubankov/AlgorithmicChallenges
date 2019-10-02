#include "5_SumLists.h"
#include "DataStructures/ListNode.h"
#include <gtest/gtest.h>
#include <vector>

TEST(SumLists, test) {
    auto a = createList({7,1,6});
    auto b = createList({5,9,2});
    auto sum = sumLists(a, b);
    std::vector<int> result = {2,1,9};
    for (auto d : result) {
        ASSERT_EQ(d, sum->val);
        sum = sum->next;
    }

    ASSERT_FALSE(sum);
}
