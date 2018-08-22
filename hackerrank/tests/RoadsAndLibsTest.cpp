#include "../RoadsAndLibs.h"
#include <gtest/gtest.h>

namespace hackerrank
{

  TEST(RoadsAndLibs, testRoadCheaperThanLib)
  {
    HackerLand hackerLand;
    hackerLand._citiesCnt = 3;
    hackerLand._libCost = 2;
    hackerLand._roadCost = 1;
    hackerLand._roads.push_back(HackerRoad{ 1, 2 });
    hackerLand._roads.push_back(HackerRoad{ 3, 1 });
    hackerLand._roads.push_back(HackerRoad{ 2, 3 });

    ASSERT_EQ(4, getMinLibAccessCost(hackerLand));
  }


  TEST(RoadsAndLibs, testLibCheaperThanRoad)
  {
    HackerLand hackerLand;
    hackerLand._citiesCnt = 6;
    hackerLand._libCost = 2;
    hackerLand._roadCost = 5;
    hackerLand._roads.push_back(HackerRoad{ 1, 3 });
    hackerLand._roads.push_back(HackerRoad{ 3, 4 });
    hackerLand._roads.push_back(HackerRoad{ 2, 4 });
    hackerLand._roads.push_back(HackerRoad{ 1, 2 });
    hackerLand._roads.push_back(HackerRoad{ 2, 3 });
    hackerLand._roads.push_back(HackerRoad{ 4, 6 });

    ASSERT_EQ(12, getMinLibAccessCost(hackerLand));
  }

}//namespace hackerrank

