#include "4_Partition.h"
#include <gtest/gtest.h>

namespace {

ListNode* addNode(ListNode* tail, int val) {
    auto newNode = new ListNode(val);
    if (tail) {
        tail->next = newNode;
        return tail->next;
    } else {
        return newNode;
    }
}

}

TEST(Partition, test) {
    ListNode *head = nullptr, *tail = nullptr;
    head = tail = new ListNode(1);
    tail = addNode(tail, 4);
    tail = addNode(tail, 3);
    tail = addNode(tail, 2);
    tail = addNode(tail, 5);
    addNode(tail, 2);

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
