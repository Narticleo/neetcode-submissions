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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy, *node;
        int carry = 0;
        while(l1 && l2){
            int digit = l1->val + l2->val + carry;
            node = new ListNode(digit % 10);
            carry = digit / 10;
            prev->next = node;
            prev = node;
            l1 = l1->next;
            l2 = l2->next;
        }        
        ListNode *remain = l1? l1 : (l2? l2 : nullptr);
        while(remain){
            int digit = carry + remain->val;
            prev->next = new ListNode(digit % 10);
            prev = prev->next;
            remain = remain->next;
            carry = digit / 10;
        }
        if(carry)prev->next = new ListNode(1);
        ListNode *head = dummy->next;
        delete(dummy);
        return head;
    }
};
