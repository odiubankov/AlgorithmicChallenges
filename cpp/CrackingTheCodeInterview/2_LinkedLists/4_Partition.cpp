#include "4_Partition.h"

namespace {

void addNext(ListNode*& head, ListNode*& tail, ListNode* next) {
    if (tail) {
        tail->next = next;
        tail = tail->next;
    } else {
        head = tail = next;
    }
}

ListNode* mergeLists(ListNode* leftHead, ListNode* leftTail, ListNode* rightHead, ListNode* rightTail) {
    if (!leftHead) {
        return rightHead;
    } else {
        leftTail->next = rightHead;
        if (rightTail)
            rightTail->next = nullptr;
        return leftHead;
    }
}

}

ListNode* partition(ListNode* head, int x) {
    ListNode* leftHead = nullptr, *leftTail = nullptr, *rightHead = nullptr, *rightTail = nullptr, *runner = head;
    while (runner) {
        if (runner->val < x)
            addNext(leftHead, leftTail, runner);
        else
            addNext(rightHead, rightTail, runner);

        runner = runner->next;
    }

    return mergeLists(leftHead, leftTail, rightHead, rightTail);
}
