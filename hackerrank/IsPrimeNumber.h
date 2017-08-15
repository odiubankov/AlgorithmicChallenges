/*
* Time Complexity: Primality
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

#ifndef HACKERRANK_ISPRIMENUMBERTEST_H
#define HACKERRANK_ISPRIMENUMBERTEST_H

#include <vector>
#include <unordered_set>

namespace hackerrank
{

bool isPrime2(int n)
{
    if (n <= 1)
        return false;

    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

        i = i + 6;
    }

    return true;
}

bool isPrime(int val)
{
    if (val == 1)
        return false;

    if (val == 2)
        return true;

    static std::unordered_set<int> primeNumbers;
    if (primeNumbers.find(val) != end(primeNumbers))
        return true;

    static std::unordered_set<int> nonPrimeNumbers;
    if (nonPrimeNumbers.find(val) != end(nonPrimeNumbers))
        return false;

    for (int i = 2; i <= val / 2; ++i) {
        if (val % i == 0) {
            nonPrimeNumbers.insert(val);
            return false;
        }
    }

    primeNumbers.insert(val);
    return true;
}

}//namespace hackerrank

#endif //HACKERRANK_ISPRIMENUMBERTEST_H
