#include "Solution.h"
#include <gtest/gtest.h>

TEST(BiweeklyContest11, test) {
    vector<int> servers{3,3,2};
    vector<int> tasks{1,2,3,2,1,2};
    vector<int> res{2,2,0,2,1,2};

    ASSERT_EQ(res, assignTasks(servers, tasks));
}
