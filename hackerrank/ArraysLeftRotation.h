#ifndef HACKERRANK_ARRAYSLEFTROTATION_H
#define HACKERRANK_ARRAYSLEFTROTATION_H

#include <vector>
#include <iterator>

using namespace std;

namespace hackerrank
{
    vector<int> array_left_rotation(vector<int> a, int n, int k) {
        vector<int> result;
        result.reserve(a.size());
        auto rotationMedian = begin(a) + k;
        copy(rotationMedian, end(a), back_inserter(result));
        copy(begin(a), rotationMedian, back_inserter(result));
        return result;
    }
}

#endif //HACKERRANK_ARRAYSLEFTROTATION_H
