class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* fast = head, * slow = head, * prev = nullptr;
        for(int i=0; i<n; i++)
            fast = fast->next;
        
        while(fast){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev) prev->next =  slow->next;
        else if(slow->next) head = slow->next;
        else head = prev;
        delete(slow);
        return head;
    }

};
