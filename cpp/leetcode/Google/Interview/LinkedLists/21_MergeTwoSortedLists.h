//https://leetcode.com/problems/merge-two-sorted-lists/
#ifndef ALGORITHMICCHALLENGES_21_MERGE_TWO_SORTED_LISTS_H
#define ALGORITHMICCHALLENGES_21_MERGE_TWO_SORTED_LISTS_H

class SolutionMergeTwoSortedLists {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode* head = nullptr;
        if (l1->val < l2->val)  {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* runner = head;
        for(;;) {
            if (l1 == nullptr) {
                runner->next = l2;
                return head;
            }
            if (l2 == nullptr) {
                runner->next = l1;
                return head;
            }
            if (l1->val < l2->val)  {
                runner->next = l1;
                l1 = l1->next;
            } else {
                runner->next = l2;
                l2 = l2->next;
            }
            runner = runner->next;
        }
    }
};

#endif //ALGORITHMICCHALLENGES_21_MERGE_TWO_SORTED_LISTS_H
