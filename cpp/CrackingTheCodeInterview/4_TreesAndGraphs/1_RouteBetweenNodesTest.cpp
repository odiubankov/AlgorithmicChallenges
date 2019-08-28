#include "1_RouteBetweenNodes.h"
#include <gtest/gtest.h>

TEST(RouteBetweenNodes, NoRoute)
{
    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();
    ASSERT_FALSE(routeBetweenNodes(a, b));
}

TEST(RouteBetweenNodes, DirectRoute)
{
    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();
    a->children_.push_back(b);
    ASSERT_TRUE(routeBetweenNodes(a, b));
    ASSERT_TRUE(routeBetweenNodes(b, a));
}

TEST(RouteBetweenNodes, InDirectRoute)
{
    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();
    a->children_.push_back(b);
    auto c = std::make_shared<Node>();
    b->children_.push_back(c);
    ASSERT_TRUE(routeBetweenNodes(a, c));
    ASSERT_TRUE(routeBetweenNodes(c, a));
}
