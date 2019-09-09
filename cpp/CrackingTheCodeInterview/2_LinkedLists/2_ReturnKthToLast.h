//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#ifndef ALGORITHMICCHALLENGES_2_RETURNKTHTOLAST_H
#define ALGORITHMICCHALLENGES_2_RETURNKTHTOLAST_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{nullptr} {}
};

ListNode* removeNthFromEnd(ListNode* head, int n);

#endif //ALGORITHMICCHALLENGES_2_RETURNKTHTOLAST_H
