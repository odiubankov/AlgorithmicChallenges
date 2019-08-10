#include "../BagsQueuesStacks_1.3.38_DeleteKthElement.h"
#include <gtest/gtest.h>

TEST(BagsQueuesStacks_DeleteKthElement, empty)
{
    sedgewick::GeneralizedQueue<int> generalizedQueue;
    ASSERT_TRUE(generalizedQueue.isEmpty());
}

TEST(BagsQueuesStacks_DeleteKthElement, non_empty)
{
    sedgewick::GeneralizedQueue<int> generalizedQueue;
    generalizedQueue.insert(0);
    ASSERT_FALSE(generalizedQueue.isEmpty());
}

TEST(BagsQueuesStacks_DeleteKthElement, remove_first)
{
    sedgewick::GeneralizedQueue<int> generalizedQueue;
    int insertedValue = 1;
    generalizedQueue.insert(insertedValue);
    ASSERT_EQ(insertedValue, generalizedQueue.remove(0));
}

TEST(BagsQueuesStacks_DeleteKthElement, remove_5_5time)
{
    sedgewick::GeneralizedQueue<int> generalizedQueue;
    for (int i = 0; i < 10; ++i)
        generalizedQueue.insert(i);

    for (int i = 0; i < 5; ++i)
        ASSERT_EQ(5-i-1, generalizedQueue.remove(5));
}

TEST(BagsQueuesStacks_DeleteKthElement, remove_and_add_multiple_times)
{
    sedgewick::GeneralizedQueue<int> generalizedQueue;
    generalizedQueue.insert(0);
    ASSERT_EQ(0, generalizedQueue.remove(0));
    generalizedQueue.insert(1);
    ASSERT_EQ(1, generalizedQueue.remove(0));
}