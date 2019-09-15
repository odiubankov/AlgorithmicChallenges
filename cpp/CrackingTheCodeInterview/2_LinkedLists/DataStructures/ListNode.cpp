#include "ListNode.h"

int getLength(ListNode* head) {
    int length = 0;
    while (head) {
        ++length;
        head = head->next;
    }

    return length;
}


ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty())
        return nullptr;

    auto it = begin(vals);
    ListNode* head = new ListNode(*it);
    ListNode* current = head;
    ++it;
    for (;it != end(vals); ++it) {
        current->next = new ListNode(*it);
        current = current->next;
    }

    return head;
}
