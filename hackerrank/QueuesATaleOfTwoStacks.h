/*
* Queues: A Tale of Two Stacks
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

#ifndef HACKERRANK_QUEUESATALEOFTWOSTACKS_H
#define HACKERRANK_QUEUESATALEOFTWOSTACKS_H

#include <stack>
#include <queue>

namespace hackerrank
{

class MyQueue
{

    void fillOutbox()
    {
        if (stack_oldest_on_top.empty()) {
            while (!stack_newest_on_top.empty()) {
                const auto& stackNewestOnTopTop = stack_newest_on_top.top();
                stack_oldest_on_top.push(stackNewestOnTopTop);
                stack_newest_on_top.pop();
            }
        }
    }

public:
    std::stack<int> stack_newest_on_top, stack_oldest_on_top;
    void push(int x)
    {
        stack_newest_on_top.push(x);
    }

    void pop()
    {
        fillOutbox();
        stack_oldest_on_top.pop();
    }

    int front()
    {
        fillOutbox();
        return stack_oldest_on_top.top();
    }
};

}//namespace hackerrank

#endif //HACKERRANK_QUEUESATALEOFTWOSTACKS_H
