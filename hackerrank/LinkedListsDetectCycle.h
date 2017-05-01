#ifndef LEETCODESOLUTIONS_LINKEDLISTSDETECTCYCLE_H
#define LEETCODESOLUTIONS_LINKEDLISTSDETECTCYCLE_H

#include <unordered_set>

using namespace std;

namespace hackerrank
{
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: */
struct Node {
    int data;
    struct Node* next;
};


    bool has_cycle(Node* head) {
        unordered_set<Node*> visitedNodes;
        while (head != nullptr)
        {
            auto insertRes = visitedNodes.insert(head);
            if (!insertRes.second)
                return true;

            head = head->next;
        }

        return false;
    }


}

#endif //LEETCODESOLUTIONS_LINKEDLISTSDETECTCYCLE_H
