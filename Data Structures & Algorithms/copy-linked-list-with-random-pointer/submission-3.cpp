/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)return nullptr;
        unordered_map<Node*, int> atoi;
        unordered_map<int, Node*> itoa;
        atoi[nullptr] = -1;
        itoa[-1] = nullptr;
        Node *cur1 = head, *prev = nullptr, *node, *head2, *cur2;
        int i = 0;
        while(cur1){
            node = new Node(cur1->val);
            if(prev)prev->next = node;
            else head2 = node;
            atoi[cur1] = i;
            itoa[i] = node;
            i++;
            prev = node;
            cur1 = cur1->next;
        }
        node->next = nullptr;
        cur1 = head;
        cur2 = head2;
        while(cur1){
            i = atoi[cur1->random];
            cur2->random = itoa[i];
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return head2;
    }
};
