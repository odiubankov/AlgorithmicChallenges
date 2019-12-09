//https://leetcode.com/problems/maximum-product-subarray/
#ifndef ALGORITHMICCHALLENGES_152_MAXIMUMPRODUCTSUBARRAY_H
#define ALGORITHMICCHALLENGES_152_MAXIMUMPRODUCTSUBARRAY_H

#include <vector>
using namespace std;

//int getMaxProduct(int product, int firstNegativeMultiplier, int lastNegativeMultiplier, size_t productLength) {
//    if (product < 0) {
//        if (firstNegativeMultiplier != 0 && lastNegativeMultiplier != 0 && productLength > 1) {
//            product /= max(firstNegativeMultiplier, lastNegativeMultiplier);
//        }
//    }
//    return product;
//}
//
//int maxProduct(const vector<int>& nums) {
//    auto numIt = begin(nums);
//    int maxProduct_ = *numIt;
//    int product = *numIt;
//    int firstNegativeMultiplier = 0;
//    int lastNegativeMultiplier = 0;
//    if (product < 0) {
//        firstNegativeMultiplier = product;
//        lastNegativeMultiplier = product;
//    }
//    size_t productLength = 1;
//    ++numIt;
//    for (; numIt != end(nums); ++numIt) {
//        if (*numIt == 0) {
//            product = getMaxProduct(product, firstNegativeMultiplier, lastNegativeMultiplier, productLength);
//            maxProduct_ = max(maxProduct_, product);
//            product = 0;
//            firstNegativeMultiplier = 0;
//            lastNegativeMultiplier = 0;
//            productLength = 0;
//            maxProduct_ = max(maxProduct_, 0);
//        } else {
//            if (product == 0) {
//                product = *numIt;
//                productLength = 1;
//            } else {
//                product *= *numIt;
//                ++productLength;
//            }
//            if (product < 0) {
//                if (firstNegativeMultiplier == 0) {
//                    firstNegativeMultiplier = product;
//                }
//                if (*numIt < 0) {
//                    lastNegativeMultiplier = *numIt;
//                } else {
//                    lastNegativeMultiplier *= *numIt;
//                }
//            }
//        }
//    }
//    product = getMaxProduct(product, firstNegativeMultiplier, lastNegativeMultiplier, productLength);
//    maxProduct_ = max(maxProduct_, product);
//    return maxProduct_;
//}

int maxProduct(const vector<int>& nums){
    int maxProduct_ = nums.front();
    int maxI = nums.front();
    int minI = nums.front();
    for (auto numIt = begin(nums) + 1; numIt != end(nums); ++numIt) {
        if (*numIt < 0)
            swap(minI, maxI);
        maxI *= *numIt;
        maxI = max(maxI, *numIt);//handling 0   
        minI *= *numIt;
        minI = min(minI, *numIt);//handling 0
        maxProduct_ = max(maxProduct_, maxI);
    }
    return maxProduct_;
}

#endif //ALGORITHMICCHALLENGES_152_MAXIMUMPRODUCTSUBARRAY_H
