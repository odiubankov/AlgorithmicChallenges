#include "Distance.h"
#include <gtest/gtest.h>
#include <vector>
#include <list>


TEST(Distance, test)
{
    std::vector<int> v{1,2,3};
    ASSERT_EQ(ostd::distance(std::begin(v), std::end(v)), v.size());

    std::list<int> l{1,2};
    ASSERT_EQ(ostd::distance(std::begin(l), std::end(l)), l.size());
}
