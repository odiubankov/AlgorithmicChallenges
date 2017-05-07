#ifndef LEETCODESOLUTIONS_SORTINGBUBBLESORT_H
#define LEETCODESOLUTIONS_SORTINGBUBBLESORT_H

#include <vector>

using namespace std;

namespace hackerrank
{
    int bubbleSortSwapsCount(vector<int>& a)
    {
        int totalSwapsCnt = 0;
        auto n = a.size();
        for (int i = 0; i < n; ++i) {
            // Track number of elements swapped during a single array traversal
            int numberOfSwaps = 0;

            for (int j = 0; j < n - 1; j++) {
                // Swap adjacent elements if they are in decreasing order
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
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
}

#endif //LEETCODESOLUTIONS_SORTINGBUBBLESORT_H
