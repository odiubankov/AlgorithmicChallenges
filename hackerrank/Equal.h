/**
* Equal (dynamic programming)
*
* https://www.hackerrank.com/challenges/equal
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef HACKERRANK_EQUAL_H
#define HACKERRANK_EQUAL_H

#include <iostream>
#include <vector>
//#include <algorithm>
#include <set>
#include <complex>

namespace hackerrank
{

  std::vector<std::vector<int>> readInput()
  {
    int queriesCnt = 0;
    std::cin >> queriesCnt;
    std::vector<std::vector<int>> queries(queriesCnt);
    for (auto& query : queries)
    {
      int peopleCnt = 0;
      std::cin >> peopleCnt;
      query.resize(peopleCnt);
      for (int i = 0; i < peopleCnt; ++i)
        std::cin >> query[i];
    }

    return queries;
  }


  int getDiffOperationsCnt1(int diff)
  {
    auto cnt5 = diff / 5;
    diff -= cnt5 * 5;
    auto cnt2 = diff / 2;
    diff -= cnt2 * 2;
    auto cnt1 = diff;
    return cnt1 + cnt2 * 2 + cnt5 * 5;
  }


  int getDiffOperationsCnt2(int diff, int& additionalDiff)
  {
    auto cnt5 = diff / 5 + 1;
    diff -= cnt5 * 5;
    diff = additionalDiff = -diff;
    auto cnt2 = diff / 2;
    diff -= cnt2 * 2;
    auto cnt1 = diff;
    return cnt1 + cnt2 * 2 + cnt5 * 5;
  }


  int getMinOperationsCnt(std::vector<int>::iterator rangeBegin, std::vector<int>::iterator rangeEnd, int& additionalAddOut)
  {
    if (std::distance(rangeBegin, rangeEnd) == 3)
    {
      auto cnt1 = getDiffOperationsCnt1(*(rangeBegin + 1) - *rangeBegin);
      auto additionalAdd = 0;

    }

    int additionalAdd = 0;
    auto minOperationsCnt = getMinOperationsCnt(rangeBegin, rangeEnd - 1, additionalAdd);
    auto diff = *(rangeEnd - 1) - *(rangeEnd - 2) + additionalAdd;
    auto cnt5 = diff / 5;
    diff -= cnt5 * 5;
    auto cnt2 = diff / 2;
    diff -= cnt2 * 2;
    auto cnt1 = diff;
    additionalAddOut = cnt1 + cnt2 * 2 + cnt5 * 5;
    return minOperationsCnt + cnt1 + cnt2 + cnt5;
  }


  int getMinOperationsCnt(std::vector<int>& peopleChocolates)
  {
    if (peopleChocolates.size() <= 1)
      return 0;

    std::sort(begin(peopleChocolates), end(peopleChocolates));
    if (peopleChocolates.size() == 2)
      return getDiffOperationsCnt1(peopleChocolates.back() - peopleChocolates.front());

    auto temp = 0;
    return getMinOperationsCnt(begin(peopleChocolates), end(peopleChocolates), temp);
  }
}//namespace hackerrank

#endif //HACKERRANK_EQUAL_H
