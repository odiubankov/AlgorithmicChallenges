#include "2_ReturnKthToLast.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n == 0)
        return head;

    auto runner = head;
    for (int i = 0; i < n; ++i) {
        if (runner)
            runner = runner->next;
        else
            return head;
    }

    auto nthFromEnd = head;
    ListNode* nthPrev = nullptr;
    while (runner) {
        nthPrev = nthFromEnd;
        runner = runner->next;
        nthFromEnd = nthFromEnd->next;
    }

    auto newHead = head;
    if (nthPrev)
        nthPrev->next = nthFromEnd->next;
    else
        newHead = nthFromEnd->next;

    delete nthFromEnd;
    return newHead;
}
