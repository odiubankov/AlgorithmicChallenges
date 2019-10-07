//https://leetcode.com/contest/biweekly-contest-10/problems/intersection-of-three-sorted-arrays/

#ifndef ALGORITHMICCHALLENGES_INTERSECTIONOFTHREESORTEDARRAYS_H
#define ALGORITHMICCHALLENGES_INTERSECTIONOFTHREESORTEDARRAYS_H

#include <vector>

class SolutionItersectionOfThreeSortedArrays {
public:
    std::vector<int> arraysIntersection(
        const std::vector<int> &arr1, const std::vector<int> &arr2, const std::vector<int> &arr3) {
        std::vector<int> result;
        auto it1 = begin(arr1);
        auto it2 = begin(arr2);
        auto it3 = begin(arr3);
        while (it1 != end(arr1) && it2 != end(arr2) && it3 != end(arr3)) {
            if (*it1 == *it2 && *it2 == *it3) {
                result.push_back(*it1);
                ++it1;
                ++it2;
                ++it3;
            }
            else {
                std::vector < std::vector<int>::const_iterator* > iterators{&it1, &it2, &it3};
                std::sort(begin(iterators), end(iterators),
                          [](auto first, auto second)
                          { return **first < **second; });
                if (**(iterators[0]) == **(iterators[1])) {
                    ++*(iterators[0]);
                    ++*(iterators[1]);
                }
                else {
                    ++*(iterators[0]);
                }
            };
        }

        return result;
    }
};

#endif //ALGORITHMICCHALLENGES_INTERSECTIONOFTHREESORTEDARRAYS_H
