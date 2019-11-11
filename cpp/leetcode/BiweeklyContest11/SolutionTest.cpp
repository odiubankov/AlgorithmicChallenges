#include "Solution.h"
#include <gtest/gtest.h>

TEST(BiweeklyContest11, test) {
//    ASSERT_EQ(9, missingNumber({5,7,11,13}));
//    ASSERT_EQ(14, missingNumber({15,13,12}));
//    std::vector<int> res{60,68};
//    ASSERT_EQ(res, minAvailableDuration({{10,50},{60,120},{140,210}}, {{0,15},{60,70}}, 8));
//    ASSERT_TRUE(minAvailableDuration({{10,50},{60,120},{140,210}}, {{0,15},{60,70}}, 12).empty());
//    std::vector<int> res{98730764,99186849};
//    std::vector<std::vector<int>> slots1{{216397070,363167701},{98730764,158208909},{441003187,466254040},{558239978,678368334},{683942980,717766451}};
//    std::vector<std::vector<int>> slots2{{50490609,222653186},{512711631,670791418},{730229023,802410205},{812553104,891266775},{230032010,399152578}};
//    ASSERT_EQ(res, minAvailableDuration(slots1, slots2, 456085));
    ASSERT_DOUBLE_EQ(0.4, probabilityOfHeads({0.4}, 1));
    ASSERT_DOUBLE_EQ(0.03125, probabilityOfHeads({0.5,0.5,0.5,0.5,0.5}, 0));
    ASSERT_DOUBLE_EQ(0.182, probabilityOfHeads({0.2,0.8,0,0.3,0.5}, 3));
}
