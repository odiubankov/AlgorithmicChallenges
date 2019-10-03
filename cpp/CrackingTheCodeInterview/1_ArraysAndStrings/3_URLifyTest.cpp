#include "3_URLify.h"
#include <gtest/gtest.h>

TEST(URLify, test) {
    ASSERT_EQ("Mr%20John%20Smith", urlify("Mr John Smith"));
}
