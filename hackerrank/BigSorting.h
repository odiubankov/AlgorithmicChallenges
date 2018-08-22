/**
* Big Sorting (sorting)
*
* https://www.hackerrank.com/challenges/big-sorting
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

#ifndef HACKERRANK_BIGSORTING_H
#define HACKERRANK_BIGSORTING_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace hackerrank
{
  void bigSorting(std::vector<std::string>& numbers)
  {
    std::sort(begin(numbers), end(numbers), [](const auto& numberA, const auto& numberB) {
      if (numberA.size() != numberB.size())
        return numberA.size() < numberB.size();

      return numberA < numberB;
    });
  }


  std::vector<std::string> readInput()
  {
    std::size_t n = 0;
    std::cin >> n;
    std::vector<std::string> unsorted(n);
    for (auto& str : unsorted)
      std::cin >> str;

    return unsorted;
  }


  void writeOutput(const std::vector<std::string>& numbers)
  {
    for (const auto& str : numbers)
      std::cout << str << std::endl;
  }


  //int main() {
  //  auto numbers = readInput();
  //  bigSorting(numbers);
  //  writeOutput(numbers);
  //  return 0;
  //}
}//namespace hackerrank

#endif //HACKERRANK_BIGSORTING_H
