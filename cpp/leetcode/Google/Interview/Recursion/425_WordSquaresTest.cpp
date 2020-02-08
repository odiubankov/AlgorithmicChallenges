#include "425_WordSquares.h"
#include <gtest/gtest.h>

TEST(WordSquares, test) {
    ASSERT_EQ(2, WordSquares::wordSquares({"area","lead","wall","lady","ball"}).size());
}

TEST(WordSquares, test2) {
    ASSERT_EQ(1, WordSquares::wordSquares({"a"}).size());
}

TEST(WordSquares, test3) {
    ASSERT_EQ(1, WordSquares::wordSquares({"ab", "bc"}).size());
}

TEST(WordSquares, test4) {
    ASSERT_EQ(2, WordSquares::wordSquares({"ab", "bc", "bd"}).size());
}

TEST(WordSquares, test5) {
    ASSERT_EQ(2, WordSquares::wordSquares({"ab", "cb", "bd"}).size());
}

TEST(WordSquares, test6) {
    ASSERT_EQ(4, WordSquares::wordSquares({"ab", "cb", "bd", "be"}).size());
}
//abc
//bde
//cef

TEST(WordSquares, test7) {
    ASSERT_EQ(1, WordSquares::wordSquares({"abc", "bde", "cef"}).size());
}
