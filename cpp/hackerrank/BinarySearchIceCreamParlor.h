/**
* Binary Search: Ice Cream Parlor
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

#ifndef HACKERRANK_ICECREAMPARLOR_H
#define HACKERRANK_ICECREAMPARLOR_H

#include <vector>

namespace hackerrank
{

class IceCream
{

public:
    int flavor;
    int index;

    IceCream(int f, int i)
        : flavor(f), index(i)
    {}
};


bool operator<(const IceCream &first, const IceCream &second)
{
    return first.flavor < second.flavor;
}


int binarySearch(int first, int last, std::vector<IceCream> arr, int search)
{
    if (last < first)
        return -1;

    int middleIndex = first + (last - first) / 2;
    if (arr[middleIndex].flavor < search)
        return binarySearch(middleIndex + 1, last, arr, search);

    if (arr[middleIndex].flavor > search)
        return binarySearch(first, middleIndex - 1, arr, search);

    return middleIndex;
}

}//namespace hackerrank

#endif //HACKERRANK_ICECREAMPARLOR_H
