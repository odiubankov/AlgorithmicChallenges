#ifndef LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H
#define LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H

#include <vector>

using namespace std;

namespace hackerrank
{
long long countInversionsImpl(vector<int>& a)
{
    if (a.size() < 2)
        return 0;

    vector<int> arr1(begin(a), begin(a) + a.size() / 2);
    vector<int> arr2(begin(a) + a.size() / 2, end(a));
    auto invCnt = countInversionsImpl(arr1) + countInversionsImpl(arr2);
    for (auto arr1It = begin(arr1); arr1It != end(arr1); ++arr1It)
    {
        auto arr2It = lower_bound(begin(arr2), end(arr2), *arr1It);
        invCnt += distance(begin(arr2), arr2It);
    }

    vector<int> temp;
    temp.reserve(a.size());
    std::merge(begin(arr1), end(arr1), begin(arr2), end(arr2), back_inserter(temp));
    a = temp;
    return invCnt;
}

long long count_inversions(vector<int> a)
{
    return countInversionsImpl(a);
}
}

#endif //LEETCODESOLUTIONS_MERGESORTCOUNTINGINVERSIONS_H
