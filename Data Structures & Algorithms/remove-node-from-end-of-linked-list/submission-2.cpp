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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* cur = head;
        while(cur){
            size++;
            cur = cur->next;
        }      
        if(size == n){
            ListNode* tmp = head;
            head = head->next;
            delete(tmp);
            return head;
        }
        int remove = size - n;
        cur = head;
        int count = 0;
        while(count++ != remove - 1)
            cur = cur->next;
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete(tmp);  
        return head;
    }
};

