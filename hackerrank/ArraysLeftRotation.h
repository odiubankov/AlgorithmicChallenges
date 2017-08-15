/*
* Arrays: Left Rotation
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

#ifndef HACKERRANK_ARRAYSLEFTROTATION_H
#define HACKERRANK_ARRAYSLEFTROTATION_H

#include <vector>
#include <iterator>

namespace hackerrank
{

std::vector<int> array_left_rotation(std::vector<int> a, int n, int k)
{
    std::vector<int> result;
    result.reserve(a.size());
    auto rotationMedian = begin(a) + k;
    copy(rotationMedian, end(a), back_inserter(result));
    copy(begin(a), rotationMedian, back_inserter(result));
    return result;
}

}//namespace hackerrank

#endif //HACKERRANK_ARRAYSLEFTROTATION_H
