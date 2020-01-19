/**
* https://leetcode.com/problems/basic-calculator-ii/#/description
*
* Implement a basic calculator to evaluate a simple expression string.
* The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
* The integer division should truncate toward zero.
* You may assume that the given expression is always valid.
*
* Some examples:
* "3+2*2" = 7
* " 3/2 " = 1
* " 3+5 / 2 " = 5
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

#ifndef LEETCODESOLUTIONS_BASICCALCULATOR_H
#define LEETCODESOLUTIONS_BASICCALCULATOR_H

#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

namespace leetcode {

int calculate(const string& s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0;
    char op = 0;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= (op == '+' ? 1 : -1);
        } else {
            long long n = 0;
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

}//namespace leetcode

#endif //LEETCODESOLUTIONS_BASICCALCULATOR_H
