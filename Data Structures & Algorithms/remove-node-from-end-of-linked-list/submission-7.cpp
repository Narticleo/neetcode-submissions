class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
            if(!fast)
                break;
        }
        while(fast)
        {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        if(pre)
        {
            pre->next = slow->next;
        }
        else if(slow->next)
        {
            head = slow->next;
        }
        else
        {
            head = pre;
        }
        return head;
    }
};