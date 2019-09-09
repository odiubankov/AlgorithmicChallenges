#include "2_ReturnKthToLast.h"
#include <gtest/gtest.h>

#include <array>

ListNode* addToEnd(ListNode* endNode, int value) {
    endNode->next = new ListNode(value);
    return endNode->next;
}

TEST(RemoveKthFromLast, test) {
    auto head = new ListNode(1);
    auto lastNode = head;
    for (int i = 2; i <= 5; ++i)
        lastNode = addToEnd(lastNode, i);

    auto newHead = removeNthFromEnd(head, 2);
    ASSERT_EQ(head, newHead);
    std::array<int, 4> listVals{ 1, 2, 3, 5 };
    auto listIt = head;
    for (auto item : listVals) {

        ASSERT_EQ(item, listIt->val);
        listIt = listIt->next;
    }

    ASSERT_EQ(listIt, nullptr);
}