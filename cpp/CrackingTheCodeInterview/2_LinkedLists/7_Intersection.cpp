#include "7_Intersection.h"
#include "DataStructures/ListNode.h"
#include <tuple>
#include <unordered_set>

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

ListNode* getIntersectionNodeFast(ListNode* headA, ListNode* headB) {
    std::unordered_set<ListNode*> aNodes, bNodes;
    while (headA || headB) {
        if (headA)
            aNodes.insert(headA);
        if (headB)
            bNodes.insert(headB);
        if (headA && bNodes.find(headA) != end(bNodes))
            return headA;
        if (headB && aNodes.find(headB) != end(aNodes))
            return headB;
        if (headA)
            headA = headA->next;
        if (headB)
            headB = headB->next;
    }
    return nullptr;
}
