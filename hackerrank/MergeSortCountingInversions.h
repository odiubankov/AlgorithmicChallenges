#ifndef LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H
#define LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H

#include <vector>
#include <cstring>

using namespace std;

namespace hackerrank
{
long long countInversionsImpl(const vector<int>::iterator& aBegin, const vector<int>::iterator& aEnd)
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
    for (auto arr1It = a1Begin; arr1It != a1End; ++arr1It)
    {
        auto arr2It = lower_bound(lastArr2It, a2End, *arr1It);
        invCnt += distance(a2Begin, arr2It);
        lastArr2It = arr2It;
    }

    vector<int> temp;
    temp.reserve(arraySize);
    merge(a1Begin, a1End, a2Begin, a2End, back_inserter(temp));
    copy(begin(temp), end(temp), aBegin);
    return invCnt;
}

long long count_inversions(vector<int> a)
{
    return countInversionsImpl(begin(a), end(a));
}
}

#endif //LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H
