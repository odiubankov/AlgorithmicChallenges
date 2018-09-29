#pragma once

#include <string>
#include <unordered_map>

using namespace std;

using ResultT = unsigned long long;
using ResultCacheT = unordered_map<ResultT, unordered_map<ResultT, ResultT>>;

namespace hackerrank {


ResultT getMaxPalindromLengthToLeft(
        const string& s,
        ResultT middle,
        ResultT length,
        ResultCacheT& resultCache,
        ResultCacheT& rightCache) {
    if (length == 0)
        return 0;

    if (length == 1)
        return  1;

    auto middleCacheIt = resultCache.find(middle);
    if (middleCacheIt != end(resultCache)) {
        auto resultIt = middleCacheIt->second.find(length);
        if (resultIt != end(middleCacheIt->second))
            return resultIt->second;
    }

    ResultT palindromAtThisPoint = 1;
    auto endIt = begin(s) + middle - 1;
    auto beginIt = endIt - (length - 1);
    auto charIt = find(beginIt, endIt, *endIt);
    if (charIt != endIt) {
        palindromAtThisPoint += 1;
        palindromAtThisPoint += getMaxPalindromLengthToLeft(s, middle - 1, endIt - charIt - 1, resultCache, rightCache);
    }

    ResultT result = 0;
    if (palindromAtThisPoint >= length - 1) {
        result = palindromAtThisPoint;
    }
    else {
        auto palindromAtNextPoint = getMaxPalindromLengthToLeft(s, middle - 1, length - 1, resultCache, rightCache);
        result = max(palindromAtThisPoint, palindromAtNextPoint);
    }

    resultCache[middle][length] = result;
    rightCache[middle - length][length] = result;
    return result;
}


ResultT getMaxPalindromLengthToRight(
    const string& s,
    ResultT middle,
    ResultT length,
    ResultCacheT& resultCache,
    ResultCacheT& leftCache) {
    if (length == 0)
        return 0;

    if (length == 1)
        return 1;

    auto middleCacheIt = resultCache.find(middle);
    if (middleCacheIt != end(resultCache)) {
        auto resultIt = middleCacheIt->second.find(length);
        if (resultIt != end(middleCacheIt->second))
            return resultIt->second;
    }

    ResultT palindromAtThisPoint = 1;
    auto endIt = rend(s) - middle - 1;
    auto beginIt = endIt - (length - 1);
    auto charIt = find(beginIt, endIt, *endIt);
    if (charIt != endIt) {
        palindromAtThisPoint += 1;
        palindromAtThisPoint += getMaxPalindromLengthToRight(s, middle + 1, endIt - charIt - 1, resultCache, leftCache);
    }

    ResultT result = 0;
    if (result >= length -1) {
        result = palindromAtThisPoint;
    }
    else {
        auto palindromAtNextPoint = getMaxPalindromLengthToRight(s, middle + 1, length - 1, resultCache, leftCache);
        result = std::max(palindromAtThisPoint, palindromAtNextPoint);
    }

    resultCache[middle][length] = result;
    leftCache[middle + length][length] = result;
    return result;
}


ResultT playWithWords(const string& s) {
    ResultCacheT leftCache, rightCache;
    ResultT maxPalindromsProduct = 0;
    for (ResultT middle = 1; middle <= s.size() - 1; ++middle) {
        auto palLengthLeft = getMaxPalindromLengthToLeft(s, middle, middle, leftCache, rightCache);
        auto palLengthRight = getMaxPalindromLengthToRight(s, middle, s.size() - middle, rightCache, leftCache);
        auto palindromsProduct = palLengthLeft * palLengthRight;
        if (palindromsProduct > maxPalindromsProduct)
            maxPalindromsProduct = palindromsProduct;
    }

    return maxPalindromsProduct;
}

}
