/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> addrs;
        ListNode* cur = head;
        while(cur && addrs.find(cur) == addrs.end()){
            addrs.insert(cur);
            cur = cur->next;
        }
        return cur != nullptr;
    }
};
