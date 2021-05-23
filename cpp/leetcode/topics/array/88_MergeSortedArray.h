// https://leetcode.com/problems/merge-sorted-array/

#ifndef ALGORITHMICCHALLENGES_88_MERGESORTEDARRAY_H
#define ALGORITHMICCHALLENGES_88_MERGESORTEDARRAY_H

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int firstPos = m - 1;
    int secondPos = n - 1;
    int resPos = m + n - 1;
    while (secondPos >= 0) {
        if (firstPos == -1 || nums2[secondPos] > nums1[firstPos]) {
            nums1[resPos] = nums2[secondPos];
            --secondPos;
        } else {
            nums1[resPos] = nums1[firstPos];
            --firstPos;
        }
        --resPos;
    }
}

#endif //ALGORITHMICCHALLENGES_88_MERGESORTEDARRAY_H
