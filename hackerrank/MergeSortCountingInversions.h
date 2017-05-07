#ifndef LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H
#define LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H

#include <vector>

using namespace std;

namespace hackerrank
{
    long long countInversionsImpl(vector<int>::iterator aBegin, vector<int>::iterator aEnd)
    {
        auto arraySize = distance(aBegin, aEnd);
        if (arraySize < 2)
            return 0;

        auto leftSubArrayItBegin = aBegin;
        auto leftSubArrayItEnd = aBegin + arraySize / 2;
        auto rightSubArrayItBegin = leftSubArrayItEnd + 1;
        auto rightSubArrayItEnd = aEnd;
        auto invCnt = countInversionsImpl(leftSubArrayItBegin, leftSubArrayItEnd) +
            countInversionsImpl(rightSubArrayItBegin, rightSubArrayItEnd);

        for (auto leftSubArrayIt = leftSubArrayItBegin;
             leftSubArrayIt != leftSubArrayItEnd;
             ++leftSubArrayIt)
        {
            if (*leftSubArrayIt > *rightSubArrayItBegin)
            {
                ++invCnt;
                swap(*leftSubArrayIt, *rightSubArrayItBegin);
                for (auto rightSubArrayIt = rightSubArrayItBegin;
                     rightSubArrayIt != (rightSubArrayItEnd - 1);
                     ++rightSubArrayIt)
                {
                    if (*rightSubArrayIt > *(rightSubArrayIt + 1))
                    {
                        swap(*rightSubArrayIt, *(rightSubArrayIt + 1));
                        ++invCnt;
                    }
                }
            }
        }

        return invCnt;
    }

    long long count_inversions(vector<int> a)
    {
        return countInversionsImpl(begin(a), end(a));
    }
}

#endif //LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H
