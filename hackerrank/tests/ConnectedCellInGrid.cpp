#include "../ConnectedCellInGrid.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(ConnectedCellInGrid, test1)
{
    ASSERT_EQ(5, get_biggest_region(std::vector<std::vector<int>>
                                        {
                                            std::vector<int> {1, 1, 0, 0},
                                            std::vector<int> {0, 1, 1, 0},
                                            std::vector<int> {0, 0, 1, 0},
                                            std::vector<int> {1, 0, 0, 0}
                                        }));
}

}//namespace hackerrank
