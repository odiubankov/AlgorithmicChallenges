#ifndef ALGORITHMICCHALLENGES_LISTNODE_H
#define ALGORITHMICCHALLENGES_LISTNODE_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val{x}
        , next{nullptr} {
    }
};

int getLength(ListNode* head);
ListNode* createList(const std::vector<int>& vals);

#endif //ALGORITHMICCHALLENGES_LISTNODE_H
