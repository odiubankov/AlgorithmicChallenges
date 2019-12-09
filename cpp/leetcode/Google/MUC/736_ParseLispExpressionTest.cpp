#include "736_ParseLispExpression.h"
#include <gtest/gtest.h>

TEST(ParseLisp, test) {
    ASSERT_EQ(3, evaluate("(add 1 2)"));
}

TEST(ParseLisp, test2) {
    ASSERT_EQ(15, evaluate("(mult 3 (add 2 3))"));
}

TEST(ParseLisp, test3) {
    ASSERT_EQ(10, evaluate("(let x 2 (mult x 5))"));
}

TEST(ParseLisp, test4) {
    ASSERT_EQ(14, evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"));
}

TEST(ParseLisp, test5) {
    ASSERT_EQ(2, evaluate("(let x 3 x 2 x)"));
}

TEST(ParseLisp, test6) {
    ASSERT_EQ(5, evaluate("(let x 1 y 2 x (add x y) (add x y))"));
}

TEST(ParseLisp, test7) {
    ASSERT_EQ(6, evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))"));
}

TEST(ParseLisp, test8) {
    ASSERT_EQ(4, evaluate("(let a1 3 b2 (add a1 1) b2)"));
}
