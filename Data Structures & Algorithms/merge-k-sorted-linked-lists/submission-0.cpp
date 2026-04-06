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
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        if(l1 == nullptr)return l2;
        if(l2 == nullptr)return l1;
        if(l1->val < l2->val){
            l1->next = mergeList(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeList(l1, l2->next);
            return l2;
        } 
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = nullptr;
        for(int i=0; i<n; i++)
            head = mergeList(head, lists[i]);
        return head;
    }
};
