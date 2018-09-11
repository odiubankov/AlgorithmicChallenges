/**
*
* 1.3.9
* Write a program that takes from standard input an expression without left
* parentheses and prints the equivalent infix expression with the parentheses
* inserted. For example, given the input:
* 1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )
* your program should print:
* ( ( 1 + 2 ) * ( ( 3 - 4 ) * ( 5 - 6 ) ) )
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

#ifndef ALGORITHMICCHALLENGES_FIXINFIXEXPRESSION_H
#define ALGORITHMICCHALLENGES_FIXINFIXEXPRESSION_H

#include <string>

namespace sedgewick
{

std::string fixInfixExpression(const std::string& expression);

}//namespace sedgewick

#endif //ALGORITHMICCHALLENGES_FIXINFIXEXPRESSION_H
