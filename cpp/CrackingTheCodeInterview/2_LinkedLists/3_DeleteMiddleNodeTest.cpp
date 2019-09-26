#include "3_DeleteMiddleNode.h"
#include "DataStructures/ListNode.h"
#include <gtest/gtest.h>

TEST(DeleteMiddleNode, test) {
    auto l = createList({1, 2, 3});
    auto r = l;
    r = r->next;
    deleteNode(r);
    r = l;
    ASSERT_EQ(r->val, 1);
    r = r->next;
    ASSERT_EQ(r->val, 3);
    ASSERT_FALSE(r->next);
}
