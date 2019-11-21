//https://leetcode.com/problems/median-of-two-sorted-arrays/
#ifndef ALGORITHMICCHALLENGES_4_MEDIANOFTWOSORTEDARRAYS_H
#define ALGORITHMICCHALLENGES_4_MEDIANOFTWOSORTEDARRAYS_H

#include <vector>

class SolutionMedianOfTwoSortedArrays {
    static void countElements(const std::vector<int>& nums, int median, int& leftCnt, int& rightCnt, int& centerCnt) {
        auto lowBound = std::lower_bound(begin(nums), end(nums), median);//more or equal the median
        if (lowBound == end(nums)) {
            leftCnt += nums.size();
            return;
        }

        leftCnt += std::distance(begin(nums), lowBound);
        if (*lowBound == median) {
            auto upBound = std::upper_bound(lowBound, end(nums), median);
            centerCnt += std::distance(lowBound, upBound);
            rightCnt += std::distance(upBound, end(nums));
        } else {
            rightCnt += std::distance(lowBound, end(nums));
        }
    }

    static bool findMedian(const std::vector<int>& first, const std::vector<int>& second, double& median) {
        if (first.empty())
            return false;
        bool totalSizeEven = ((first.size() + second.size()) % 2 == 0);
        auto rangeBegin = begin(first);
        auto rangeEnd = end(first);
        for (;;) {
            auto dist = std::distance(rangeBegin, rangeEnd);
            auto midIt = rangeBegin + dist / 2;
            int leftCnt = 0, rightCnt = 0, centerCnt = 0;
            countElements(first, *midIt, leftCnt, rightCnt, centerCnt);
            countElements(second, *midIt, leftCnt, rightCnt, centerCnt);
            int diff = std::abs(leftCnt - rightCnt);
            int remainingCenters = centerCnt - diff;
            if (remainingCenters < 0) {
                if (rangeBegin == rangeEnd)
                    return false;
                if (leftCnt > rightCnt) {
                    if (midIt == rangeBegin)
                        return false;
                    rangeEnd = midIt;
                } else {
                    rangeBegin = midIt + 1;
                    if (rangeBegin == rangeEnd)
                        return false;
                }
            } else {
                if (totalSizeEven) {
                    if (remainingCenters == 0) {
                        if (rightCnt > leftCnt) {
                            int nextElement = std::numeric_limits<int>::max();
                            auto upBound = std::upper_bound(midIt, end(first), *midIt);
                            if (upBound != end(first))
                                nextElement = *upBound;
                            upBound = std::upper_bound(begin(second), end(second), *midIt);
                            if (upBound != end(second) && *upBound < nextElement)
                                nextElement = *upBound;
                            median = (*midIt + nextElement) / 2.0;
                            return true;
                        } else { //leftCnt > right cnt
                            int prevElement = std::numeric_limits<int>::min();
                            if (midIt != begin(first))
                                prevElement = *(midIt - 1);
                            auto lowBound = std::lower_bound(begin(second), end(second), *midIt);
                            if (lowBound != begin(second) && !second.empty()) {
                                --lowBound;
                                if (*lowBound > prevElement)
                                    prevElement = *lowBound;
                            }
                            median = (*midIt + prevElement) / 2.0;
                            return true;
                        }
                    } else if (remainingCenters > 1) {
                        median = *midIt;
                        return true;
                    } else if (remainingCenters == 1) {
                        assert(false);
                    }
                } else { //total size odd
                    median = *midIt;
                    return true;
                }
            }
        }
    }

public:
    double findMedianSortedArraysNoAdditionalMemory(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        double median = 0;
        if (findMedian(nums1, nums2, median))
            return median;
        findMedian(nums2, nums1, median);
        return median;
    }

    double findMedianSortedArraysMergeSort(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> resultVector;
        resultVector.reserve(nums1.size() + nums2.size());
        auto nums1It = begin(nums1);
        auto nums2It = begin(nums2);
        while (nums1It != end(nums1) || nums2It != end(nums2)) {
            if (nums1It == end(nums1))
                resultVector.push_back(*nums2It++);
            else if (nums2It == end(nums2))
                resultVector.push_back(*nums1It++);
            else {
                if (*nums1It < *nums2It)
                    resultVector.push_back(*nums1It++);
                else
                    resultVector.push_back(*nums2It++);
            }
        }

        auto middle = resultVector.size() / 2;
        if (resultVector.size() % 2 == 0) {
            return (resultVector[middle] + resultVector[middle - 1]) / 2.0;
        } else {
            return resultVector[middle];
        }
    }
};

#endif //ALGORITHMICCHALLENGES_4_MEDIANOFTWOSORTEDARRAYS_H
