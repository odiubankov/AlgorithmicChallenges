#include "6_Palindrome.h"

#include <tuple>
#include <cassert>

std::tuple<ListNode*, ListNode*> revertPart(ListNode* head, int length) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    for (int i = 0; i < length && current; ++i) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return std::make_tuple(prev, current);
}

bool isPalindrome(ListNode* head) {
    if (!head)
        return true;

    auto length = getLength(head);
    auto lengthToCheck = length / 2;
    ListNode* leftHead = nullptr, *rightHead = nullptr;
    std::tie(leftHead, rightHead) = revertPart(head, lengthToCheck);
    if (length % 2 != 0)
        rightHead = rightHead->next;

    bool palindrome = true;
    while (palindrome && leftHead && rightHead) {
        palindrome = leftHead->val == rightHead->val;
        leftHead = leftHead->next;
        rightHead = rightHead->next;
    }

    revertPart(leftHead, lengthToCheck);
    return palindrome;
}
