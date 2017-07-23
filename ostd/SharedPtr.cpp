#include "SharedPtr.h"
#include <gtest/gtest.h>

namespace{
    static const int CONST_METHOD_VAL = 0;
    static const int NON_CONST_METHOD_VAL = 1;
}


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

    int getCounterVal() const { return _ownershipCounter; }

    int constCheckMethod() const { return CONST_METHOD_VAL; }

    int constCheckMethod() { return NON_CONST_METHOD_VAL; }

private:
    int& _ownershipCounter;
};


TEST(SharedPtr, defaultConstruct)
{
    ostd::SharedPtr<int> sharedPtr;
    ASSERT_EQ(sharedPtr.get(), nullptr);
}


TEST(SharedPtr, resourceOwnership)
{
    int counter = 0;
    {
        ostd::SharedPtr<TestOwnership> sharedPtr{new TestOwnership(counter)};
        ASSERT_EQ(counter, 1);
    }
    ASSERT_EQ(counter, 0);
}


TEST(SharedPtr, copyConstruct)
{
    int counter = 0;
    {
        ostd::SharedPtr<TestOwnership> sharedPtr1{new TestOwnership(counter)};
        ostd::SharedPtr<TestOwnership> sharedPtr2(sharedPtr1);
        ASSERT_EQ(sharedPtr1->getCounterVal(), 1);
        ASSERT_EQ(sharedPtr2->getCounterVal(), 1);
    }
    ASSERT_EQ(counter, 0);
}


TEST(SharedPtr, moveConstruct)
{
    int counter = 0;
    ostd::SharedPtr<TestOwnership> ptr1{ new TestOwnership(counter) };
    ostd::SharedPtr<TestOwnership> ptr2{ std::move(ptr1) };
    ASSERT_EQ(nullptr, ptr1.get());
    ASSERT_NE(nullptr, ptr2.get());
    ASSERT_EQ(counter, 1);
}


TEST(SharedPtr, copyAssignment)
{
    int counter = 0;
    {
        ostd::SharedPtr<TestOwnership> sharedPtr1{new TestOwnership(counter)};
        ostd::SharedPtr<TestOwnership> sharedPtr2;
        sharedPtr2 = sharedPtr1;
        ASSERT_EQ(sharedPtr1->getCounterVal(), 1);
        ASSERT_EQ(sharedPtr2->getCounterVal(), 1);
    }
    ASSERT_EQ(counter, 0);
}


TEST(SharedPtr, moveAssignment)
{
    int counter = 0;
    ostd::SharedPtr<TestOwnership> ptr1{ new TestOwnership(counter) };
    ostd::SharedPtr<TestOwnership> ptr2;
    ptr2 = std::move(ptr1);
    ASSERT_EQ(nullptr, ptr1.get());
    ASSERT_NE(nullptr, ptr2.get());
    ASSERT_EQ(counter, 1);
}


TEST(SharedPtr, testPolicies)
{
    ASSERT_TRUE(std::is_copy_constructible<ostd::SharedPtr<int>>::value);
    ASSERT_TRUE(std::is_copy_assignable<ostd::SharedPtr<int>>::value);
    ASSERT_TRUE(std::is_nothrow_move_constructible<ostd::SharedPtr<int>>::value);
    ASSERT_TRUE(std::is_nothrow_move_assignable<ostd::SharedPtr<int>>::value);
}