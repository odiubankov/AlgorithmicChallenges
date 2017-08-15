/**
* Linked Lists: Detect a Cycle
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

#ifndef HACKERRANK_LINKEDLISTSDETECTCYCLE_H
#define HACKERRANK_LINKEDLISTSDETECTCYCLE_H

#include <unordered_set>

namespace hackerrank
{

struct Node
{
    int data;
    struct Node *next;
};

bool has_cycle(Node *head)
{
    std::unordered_set<Node *> visitedNodes;
    while (head != nullptr) {
        auto insertRes = visitedNodes.insert(head);
        if (!insertRes.second)
            return true;

        head = head->next;
    }

    return false;
}

}//namespace hackerrank

#endif //HACKERRANK_LINKEDLISTSDETECTCYCLE_H
