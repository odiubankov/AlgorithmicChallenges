#include "UniquePtr.h"
#include <gtest/gtest.h>

class TestOwnership
{
public:
    TestOwnership(int& ownershipCounter)
    : _ownershipCounter{ownershipCounter}
    {
        ++_ownershipCounter;
    }

    ~TestOwnership()
    {
        --_ownershipCounter;
    }

private:
    int& _ownershipCounter;
};

TEST(UniquePtr, ownership)
{
    int counter = 0;
    {
        ostd::UniquePtr<TestOwnership> ptr{new TestOwnership(counter)};
    }

    ASSERT_EQ(counter, 0);
}


TEST(UniquePtr, defaultConstruct)
{
    ostd::UniquePtr<TestOwnership> ptr;
    ASSERT_EQ(nullptr, ptr.get());
}


TEST(UniquePtr, moveConstruct)
{
    int counter = 0;
    ostd::UniquePtr<TestOwnership> ptr1{ new TestOwnership(counter) };
    ostd::UniquePtr<TestOwnership> ptr2{ std::move(ptr1) };
    ASSERT_EQ(nullptr, ptr1.get());
    ASSERT_NE(nullptr, ptr2.get());
    ASSERT_EQ(counter, 1);
}


TEST(UniquePtr, moveAssignment)
{
    int counter = 0;
    ostd::UniquePtr<TestOwnership> ptr1{ new TestOwnership(counter) };
    ostd::UniquePtr<TestOwnership> ptr2;
    ptr2 = std::move(ptr1);
    ASSERT_EQ(nullptr, ptr1.get());
    ASSERT_NE(nullptr, ptr2.get());
    ASSERT_EQ(counter, 1);
}


TEST(UniquePtr, testPolicies)
{
    ASSERT_FALSE(std::is_copy_constructible<ostd::UniquePtr<int>>::value);
    ASSERT_FALSE(std::is_copy_assignable<ostd::UniquePtr<int>>::value);
    ASSERT_TRUE(std::is_nothrow_move_constructible<ostd::UniquePtr<int>>::value);
    ASSERT_TRUE(std::is_nothrow_move_assignable<ostd::UniquePtr<int>>::value);
}
