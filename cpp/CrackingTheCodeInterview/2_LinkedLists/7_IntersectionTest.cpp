#include "7_Intersection.h"
#include "DataStructures/ListNode.h"
#include <gtest/gtest.h>

TEST(Intersection, WithIntersect_A_Shorter) {
    ListNode* aTail = nullptr, *bTail = nullptr;
    auto listA = createList({4, 1}, &aTail);
    auto listB = createList({5, 0, 1}, &bTail);
    auto listC = createList({8, 4, 1});
    aTail->next = bTail->next = listC;
    ASSERT_EQ(getIntersectionNode(listA, listB), listC);
}


TEST(Intersection, WithIntersect_B_Shorter) {
    ListNode* aTail = nullptr, *bTail = nullptr;
    auto listA = createList({0, 9, 1}, &aTail);
    auto listB = createList({3}, &bTail);
    auto listC = createList({2, 4});
    aTail->next = bTail->next = listC;
    ASSERT_EQ(getIntersectionNode(listA, listB), listC);
}


TEST(Intersection, WithoutIntersect) {
    auto listA = createList({2, 6, 4});
    auto listB = createList({1, 5});
    ASSERT_EQ(getIntersectionNode(listA, listB), nullptr);
}
