// https://leetcode.com/problems/4sum/#/description
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
#ifndef LEETCODESOLUTIONS_FOURSUM_H
#define LEETCODESOLUTIONS_FOURSUM_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

namespace foursum
{
  class Solution {

    struct VectorHash {
      inline size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
          seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
      }
    };


    using UniqueResultsT = std::unordered_set<vector<int>, VectorHash>;


    inline void insertResultIfUnique(const pair<int, int>& pair1, const pair<int, int>& pair2, const vector<int>& nums, UniqueResultsT& uniqueResult) const
    {
      if (pair1.first != pair2.first && pair1.first != pair2.second && pair1.second != pair2.first && pair1.second != pair2.second)
      {
        vector<int> result{ nums[pair1.first], nums[pair1.second], nums[pair2.first], nums[pair2.second] };
        sort(begin(result), end(result));
        uniqueResult.insert(move(result));
      }
    }


  public:
    using TwoSumValuesT = unordered_map<int, vector<pair<int, int>> >;

    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
      TwoSumValuesT twoSums;
      UniqueResultsT uniqueResult;
      int startIndex = 0;
      while (startIndex < (static_cast<int>(nums.size()) - 1))
      {
        for (size_t i = startIndex + 1; i < nums.size(); ++i)
        {
          auto twoSum = nums[startIndex] + nums[i];
          auto twoSumsIt = twoSums.find(twoSum);
          if (twoSumsIt != end(twoSums))
          {
            twoSumsIt->second.emplace_back(startIndex, i);
            if (target - twoSum == twoSum)
            {
              auto lastInsertedItemIt = twoSumsIt->second.rbegin();
              auto itemIt = lastInsertedItemIt;
              ++itemIt;
              for (; itemIt != twoSumsIt->second.rend(); ++itemIt)
              {
                insertResultIfUnique(*lastInsertedItemIt, *itemIt, nums, uniqueResult);
              }
            }
          }
          else
          {
            twoSums.emplace(twoSum, vector<pair<int, int>>{ pair<int, int>{startIndex, i} });
          }
        }
        
        ++startIndex;
      }
      
      unordered_set<int> processedSums;
      for (const auto& sum : twoSums)
      {
        auto remainingVal = target - sum.first;
        if (remainingVal != sum.first && processedSums.find(remainingVal) == end(processedSums))
        {
          processedSums.insert(sum.first);
          auto twoSumIt = twoSums.find(remainingVal);
          if (twoSumIt != end(twoSums))
          {
            for (const auto& twoSum1 : sum.second)
            {
              for (const auto& twoSum2 : twoSumIt->second)
              {
                insertResultIfUnique(twoSum1, twoSum2, nums, uniqueResult);
              }
            }
          }
        }
      }

      return vector<vector<int>> {begin(uniqueResult), end(uniqueResult)};
    }
  };
}//namespace foursum

#endif //LEETCODESOLUTIONS_FOURSUM_H
