//https://leetcode.com/problems/merge-k-sorted-lists/
#ifndef ALGORITHMICCHALLENGES_23_MERGEKSORTEDLISTS_H
#define ALGORITHMICCHALLENGES_23_MERGEKSORTEDLISTS_H

#include <vector>
using namespace std;

class SolutionMergeSorted {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    template<typename CompT>
    void updateHeap(vector<ListNode*>& lists, const CompT& comp) {
        pop_heap(begin(lists), end(lists), comp);
        auto next = lists.back()->next;
        lists.pop_back();
        if (next) {
            lists.push_back(next);
            push_heap(begin(lists), end(lists), comp);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        lists.erase(remove(begin(lists), end(lists), nullptr), end(lists));
        if (lists.empty())
            return nullptr;
        auto nodeComp = [](auto l, auto r) {
            return l->val > r->val;
        };
        make_heap(begin(lists), end(lists), nodeComp);
        auto head = lists.front();
        auto tail = head;
        updateHeap(lists, nodeComp);
        while (!lists.empty()) {
            tail->next = lists.front();
            tail = tail->next;
            updateHeap(lists, nodeComp);
        }
        tail->next = nullptr;
        return head;
    }
};

#endif //ALGORITHMICCHALLENGES_23_MERGEKSORTEDLISTS_H
