/*
* Sorting: Bubble Sort
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

#ifndef HACKERRANK_SORTINGBUBBLESORT_H
#define HACKERRANK_SORTINGBUBBLESORT_H

#include <vector>

namespace hackerrank
{

int bubbleSortSwapsCount(std::vector<int> &a)
{
    int totalSwapsCnt = 0;
    auto n = a.size();
    for (int i = 0; i < n; ++i) {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }

        totalSwapsCnt += numberOfSwaps;
    }

    return totalSwapsCnt;
}

}//namespace hackerrank

#endif //HACKERRANK_SORTINGBUBBLESORT_H
