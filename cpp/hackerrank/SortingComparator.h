/**
* Sorting: Comparator
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

#ifndef HACKERRANK_SORTINGCOMPARATOR_H
#define HACKERRANK_SORTINGCOMPARATOR_H

#include <vector>
#include <string>
#include <algorithm>

namespace hackerrank
{

struct Player
{
    std::string name;
    int score;
};

bool operator<(const Player &player1, const Player &player2)
{
    if (player1.score == player2.score) {
        return player1.name < player2.name;
    }

    return player1.score > player2.score;
}

std::vector<Player> comparator(std::vector<Player> players)
{
    sort(begin(players), end(players));
    return players;
}

}//namespace hackerrank

#endif //HACKERRANK_SORTINGCOMPARATOR_H
