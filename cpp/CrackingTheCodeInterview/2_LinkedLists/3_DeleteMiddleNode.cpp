#include "3_DeleteMiddleNode.h"
#include "DataStructures/ListNode.h"

void deleteNode(ListNode* toDelete) {
    toDelete->val = toDelete->next->val;
    auto next = toDelete->next;
    toDelete->next = toDelete->next->next;
    delete next;
}
