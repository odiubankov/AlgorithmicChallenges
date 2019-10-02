#include "8_LoopDetection.h"
#include "DataStructures/ListNode.h"

bool hasCycle(ListNode* head) {
    ListNode* iter1 = head, *iter2 = head;
    for (;;) {
        if (!iter2)
            return false;
        iter2 = iter2->next;
        if (!iter2)
            return false;
        iter2 = iter2->next;
        iter1 = iter1->next;
        if (iter2 == iter1)
            return true;
    }
}
