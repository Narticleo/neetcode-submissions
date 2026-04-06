class Solution {
private:
    int k;
    ListNode* reverseKList(ListNode *prev, ListNode* cur, int i){
        if(i == k)return cur;
        ListNode *nxt = cur->next;
        cur->next = prev;
        return reverseKList(cur, nxt, i+1);

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        this->k = k;
        int i = 0;
        ListNode* firstHead = head, *cur = head, *curGroupHead = head, *lastGroupTail = nullptr;
        while(cur){
            i++;
            if(i % k == 0){
                if(i == k)firstHead = cur;
                if(lastGroupTail)lastGroupTail->next = cur;
                cur = reverseKList(cur->next, curGroupHead, 0);
                lastGroupTail = curGroupHead;
                curGroupHead = cur;
            }else{
                cur = cur->next;
            }
        }

        return firstHead;
    }
};