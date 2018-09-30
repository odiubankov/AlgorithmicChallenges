#pragma once

#include <string>
#include <vector>

using namespace std;

using ResultT = unsigned long long;
using ResultCacheT = vector<vector<ResultT>>;

namespace hackerrank {


ResultT getMaxPalindromLengthToLeft(
        const string& s,
        ResultT middle,
        ResultT length,
        ResultCacheT& resultCache) {
    if (length == 0)
        return 0;

    if (length == 1)
        return  1;

    if (resultCache[middle][length] != 0)
        return resultCache[middle][length];

    ResultT palindromAtThisPoint = 1;
    auto endIt = begin(s) + middle - 1;
    auto beginIt = endIt - (length - 1);
    auto charIt = find(beginIt, endIt, *endIt);
    if (charIt != endIt) {
        palindromAtThisPoint += 1;
        palindromAtThisPoint += getMaxPalindromLengthToLeft(s, middle - 1, endIt - charIt - 1, resultCache);
    }

    ResultT result = 0;
    if (palindromAtThisPoint >= length - 1) {
        result = palindromAtThisPoint;
    }
    else {
        auto palindromAtNextPoint = getMaxPalindromLengthToLeft(s, middle - 1, length - 1, resultCache);
        result = max(palindromAtThisPoint, palindromAtNextPoint);
    }

    resultCache[middle][length] = result;
    return result;
}


ResultT getMaxPalindromLengthToRight(
    const string& s,
    ResultT middle,
    ResultT length,
    ResultCacheT& resultCache) {
    if (length == 0)
        return 0;

    if (length == 1)
        return 1;

    if (resultCache[middle][length] != 0)
        return resultCache[middle][length];

    ResultT palindromAtThisPoint = 1;
    auto endIt = rend(s) - middle - 1;
    auto beginIt = endIt - (length - 1);
    auto charIt = find(beginIt, endIt, *endIt);
    if (charIt != endIt) {
        palindromAtThisPoint += 1;
        palindromAtThisPoint += getMaxPalindromLengthToRight(s, middle + 1, endIt - charIt - 1, resultCache);
    }

    ResultT result = 0;
    if (result >= length -1) {
        result = palindromAtThisPoint;
    }
    else {
        auto palindromAtNextPoint = getMaxPalindromLengthToRight(s, middle + 1, length - 1, resultCache);
        result = std::max(palindromAtThisPoint, palindromAtNextPoint);
    }

    resultCache[middle][length] = result;
    return result;
}


ResultT playWithWords(const string& s) {
    ResultCacheT leftCache(s.size(), ResultCacheT::value_type(s.size(), 0));
    auto rightCache = leftCache;
    ResultT maxPalindromsProduct = 0;
    for (ResultT middle = 1; middle <= s.size() - 1; ++middle) {
        auto palLengthLeft = getMaxPalindromLengthToLeft(s, middle, middle, leftCache);
        auto palLengthRight = getMaxPalindromLengthToRight(s, middle, s.size() - middle, rightCache);
        auto palindromsProduct = palLengthLeft * palLengthRight;
        if (palindromsProduct > maxPalindromsProduct)
            maxPalindromsProduct = palindromsProduct;
    }

    return maxPalindromsProduct;
}

}
