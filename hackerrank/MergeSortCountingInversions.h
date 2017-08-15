/*
* Merge Sort: Counting Inversions
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
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

#ifndef HACKERRANK_MERGESORTCOUNTINGINVERSIONS_H
#define HACKERRANK_MERGESORTCOUNTINGINVERSIONS_H

#include <vector>
#include <cstring>
#include <algorithm>
#include <iterator>

namespace hackerrank
{

long long countInversionsImpl(const std::vector<int>::iterator &aBegin, const std::vector<int>::iterator &aEnd)
{
    auto arraySize = distance(aBegin, aEnd);
    if (arraySize < 2)
        return 0;

    auto a1Begin = aBegin;
    auto a1End = aBegin + arraySize / 2;
    auto a2Begin = a1End;
    auto a2End = aEnd;
    auto invCnt = countInversionsImpl(a1Begin, a1End) + countInversionsImpl(a2Begin, a2End);
    auto lastArr2It = a2Begin;
    for (auto arr1It = a1Begin; arr1It != a1End; ++arr1It) {
        auto arr2It = lower_bound(lastArr2It, a2End, *arr1It);
        invCnt += distance(a2Begin, arr2It);
        lastArr2It = arr2It;
    }

    std::vector<int> temp;
    temp.reserve(arraySize);
    merge(a1Begin, a1End, a2Begin, a2End, back_inserter(temp));
    copy(begin(temp), end(temp), aBegin);
    return invCnt;
}

long long count_inversions(std::vector<int> a)
{
    return countInversionsImpl(begin(a), end(a));
}

}//namespace hackerrank

#endif //HACKERRANK_MERGESORTCOUNTINGINVERSIONS_H
