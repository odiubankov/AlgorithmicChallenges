#include "5_SumLists.h"
#include "DataStructures/ListNode.h"

ListNode* sumLists(ListNode* a, ListNode* b) {
    ListNode* result = nullptr, *current = nullptr;
    int remember = 0;
    while (a || b) {
        int digit = remember;
        if (a) {
            digit += a->val;
            a = a->next;
        }

        if (b) {
            digit += b->val;
            b = b->next;
        }

        remember = digit / 10;
        auto node = new ListNode(digit % 10);
        if (!result) {
            result = current = node;
        } else {
            current->next = node;
            current = current->next;
        }
    }

    if (remember > 0) {
        current->next = new ListNode(remember);
    }

    return result;
}
