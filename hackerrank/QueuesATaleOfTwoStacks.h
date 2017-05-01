#ifndef LEETCODESOLUTIONS_QUEUESATALEOFTWOSTACKS_H
#define LEETCODESOLUTIONS_QUEUESATALEOFTWOSTACKS_H

#include <stack>
#include <queue>

using namespace std;

namespace hackerrank
{
    class MyQueue {

        void fillOutbox()
        {
            if (stack_oldest_on_top.empty())
            {
                while (!stack_newest_on_top.empty())
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
        }

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void pop() {
            fillOutbox();
            stack_oldest_on_top.pop();
        }

        int front() {
            fillOutbox();
            return stack_oldest_on_top.top();
        }
    };
}

#endif //LEETCODESOLUTIONS_QUEUESATALEOFTWOSTACKS_H
