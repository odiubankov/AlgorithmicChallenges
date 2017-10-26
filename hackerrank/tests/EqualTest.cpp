#include "../Equal.h"
#include <gtest/gtest.h>

namespace hackerrank
{

  TEST(Equal, test1)
  {
    std::vector<unsigned> peopleChocolates{ 2, 2, 3, 7 };
    ASSERT_EQ(2, getMinOperationsCnt(peopleChocolates));
  }


  TEST(Equal, test2)
  {
    std::vector<unsigned> peopleChocolates{ 1, 5, 5 };
    ASSERT_EQ(3, getMinOperationsCnt(peopleChocolates));
  }

}//namespace hackerrank

