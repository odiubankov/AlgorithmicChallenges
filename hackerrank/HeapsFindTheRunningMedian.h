/*
* Heaps: Find the Running Median
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef HACKERRANK_HEAPSFINDTHERUNNINGMEDIAN_H
#define HACKERRANK_HEAPSFINDTHERUNNINGMEDIAN_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>

namespace hackerrank
{

void pushValueAndSetMedian(std::vector<int> &leftHeap, std::vector<int> &rightHeap, int val)
{
    if (leftHeap.empty() || val <= leftHeap.front() || rightHeap.empty() || val <= rightHeap.front()) {
        leftHeap.push_back(val);
        push_heap(begin(leftHeap), end(leftHeap), std::less<int>());

        if ((leftHeap.size() - rightHeap.size()) == 2) {
            rightHeap.push_back(leftHeap.front());
            push_heap(begin(rightHeap), end(rightHeap), std::greater<int>());
            pop_heap(begin(leftHeap), end(leftHeap), std::less<int>());
            leftHeap.pop_back();
        }
    }
    else {
        rightHeap.push_back(val);
        push_heap(begin(rightHeap), end(rightHeap), std::greater<int>());

        if (rightHeap.size() > leftHeap.size()) {
            leftHeap.push_back(rightHeap.front());
            push_heap(begin(leftHeap), end(leftHeap), std::less<int>());
            pop_heap(begin(rightHeap), end(rightHeap), std::greater<int>());
            rightHeap.pop_back();
        }
    }
}

float getMedian(const std::vector<int> &leftHeap, const std::vector<int> &rightHeap)
{
    if (leftHeap.size() > rightHeap.size()) {
        return static_cast<float>(leftHeap.front());
    }
    else {
        return (leftHeap.front() + rightHeap.front()) / 2.0f;
    }
}

int heapsRunningMedian()
{
    std::cout << std::fixed << std::setprecision(1);

    std::vector<int> leftHeap;
    std::vector<int> rightHeap;

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        std::cin >> a[a_i];
        pushValueAndSetMedian(leftHeap, rightHeap, a[a_i]);
        std::cout << getMedian(leftHeap, rightHeap) << std::endl;
    }

    return 0;
}

std::vector<float> heapsRunningMedian(std::vector<int> input)
{
    std::vector<float> result;
    std::vector<int> leftHeap;
    std::vector<int> rightHeap;

    for (const auto &val : input) {
        pushValueAndSetMedian(leftHeap, rightHeap, val);
        result.push_back(getMedian(leftHeap, rightHeap));
    }

    return result;
}

}//namespace hackerrank

#endif //HACKERRANK_HEAPSFINDTHERUNNINGMEDIAN_H
