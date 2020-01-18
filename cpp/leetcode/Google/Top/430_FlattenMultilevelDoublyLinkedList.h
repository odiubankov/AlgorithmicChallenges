//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
#ifndef ALGORITHMICCHALLENGES_430_FLATTENMULTILEVELDOUBLYLINKEDLIST_H
#define ALGORITHMICCHALLENGES_430_FLATTENMULTILEVELDOUBLYLINKEDLIST_H

#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

Node* flatten(Node* head) {
    stack<Node*> branches;
    Node* runner = head, *prev = nullptr;
    while (runner) {
        runner->prev = prev;
        prev = runner;
        if (runner->child) {
            if (runner->next)
                branches.push(runner->next);
            runner->next = runner->child;
            runner->child = nullptr;
        } else {
            if (!runner->next && !branches.empty()) {
                runner->next = branches.top();
                branches.pop();
            }
        }
        runner = runner->next;
    }
    return head;
}

#endif //ALGORITHMICCHALLENGES_430_FLATTENMULTILEVELDOUBLYLINKEDLIST_H
