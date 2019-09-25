#include "7_Intersection.h"
#include "DataStructures/ListNode.h"
#include <tuple>

std::tuple<ListNode*, int> getLastAndLength(ListNode* head) {
    auto result = std::make_tuple<ListNode*, int>(nullptr, 0);
    while (head) {
        std::get<0>(result) = head;
        std::get<1>(result) += 1;
        head = head->next;
    }

    return result;
}

ListNode* getNth(ListNode* head, int n) {
    for (int i = 0; i < n; ++i)
        head = head->next;
    return head;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* lastA = nullptr, *lastB = nullptr;
    int lengthA = 0, lengthB = 0;
    std::tie(lastA, lengthA) = getLastAndLength(headA);
    std::tie(lastB, lengthB) = getLastAndLength(headB);
    if (lastA != lastB)
        return nullptr;

    if (lengthA > lengthB) {
        headA = getNth(headA, lengthA - lengthB);
    } else if (lengthB > lengthA) {
        headB = getNth(headB, lengthB - lengthA);
    }

    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}
