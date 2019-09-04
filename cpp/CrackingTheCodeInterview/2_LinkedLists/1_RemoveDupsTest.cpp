#include "1_RemoveDups.h"
#include <gtest/gtest.h>

TEST(RemoveDups, HashSet) {
    std::list<int> l{1,2,3,3,4,5,5,6,7,8,9,9,3,1,6};
    removeDups(l);
    std::list<int> noDups{1,2,3,4,5,6,7,8,9};
    ASSERT_EQ(l, noDups);
}

TEST(RemoveDups, NoExtraDataStructures) {
    std::list<int> l{1,2,3,3,4,5,5,6,7,8,9,9,3,1,6};
    removeDupsNoExtraMemory(l);
    std::list<int> noDups{1,2,3,4,5,6,7,8,9};
    ASSERT_EQ(l, noDups);
}
