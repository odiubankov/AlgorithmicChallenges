//https://leetcode.com/problems/copy-list-with-random-pointer/
#ifndef ALGORITHMICCHALLENGES_138_COPYLISTWITHRANDOMPOINTER_H
#define ALGORITHMICCHALLENGES_138_COPYLISTWITHRANDOMPOINTER_H

#include <unordered_map>
using namespace std;

class SolutionCopyListWithRandomPointer {
public:
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node() {}

        Node(int _val, Node* _next, Node* _random) {
            val = _val;
            next = _next;
            random = _random;
        }
    };

    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        int index = 0;
        unordered_map<Node*, int> nodeIndexes;
        for (auto runner = head; runner; runner = runner->next, ++index)
            nodeIndexes[runner] = index;
        auto copyHead = new Node(head->val, nullptr, nullptr);
        index = 0;
        unordered_map<int, Node*> copyIndexes;
        for (auto runner = head, copyRunner = copyHead; runner; runner = runner->next, copyRunner = copyRunner->next, ++index) {
            copyIndexes[index] = copyRunner;
            if (runner->next) {
                copyRunner->next = new Node(runner->next->val, nullptr, nullptr);
            }
        }
        for (auto runner = head, copyRunner = copyHead; runner; runner = runner->next, copyRunner = copyRunner->next) {
            if (runner->random)
                copyRunner->random = copyIndexes[nodeIndexes[runner->random]];
        }
        return copyHead;
    }
};

#endif //ALGORITHMICCHALLENGES_138_COPYLISTWITHRANDOMPOINTER_H
