#include "ConnectedCellInGrid.h"
#include <gtest/gtest.h>

TEST(ConnectedCellInGrid, test1)
{
  ASSERT_EQ(5, hackerrank::get_biggest_region(vector<vector<int>>{
      vector<int>{1, 1, 0, 0},
      vector<int>{0, 1, 1, 0},
      vector<int>{0, 0, 1, 0},
      vector<int>{1, 0, 0, 0}
  }));
}