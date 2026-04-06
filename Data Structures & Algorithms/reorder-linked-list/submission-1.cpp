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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* cur = head, *prev = nullptr, *nxt;
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == nullptr)return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *s1 = head, *s2 = reverseList(slow->next), *tmp;
        while(s2){
            tmp = s1->next;
            s1->next = s2;
            s1 = tmp;

            tmp = s2->next;
            s2->next = s1;
            s2 = tmp;
        }
        if(s1)s1->next = nullptr;
    }
};
