#include "IsSame.h"
#include <gtest/gtest.h>

namespace {
  class FirstType {};

  class SecondType {};
}

TEST(IsSame, test)
{
  bool isSame = ostd::IsSame<FirstType, FirstType>::Value;
  ASSERT_TRUE(isSame);
  isSame = ostd::IsSame<FirstType, SecondType>::Value;
  ASSERT_FALSE(isSame);
}