class Solution {
private:
    int big, small;
    TreeNode* findAncestor(TreeNode* node){
        if(node == nullptr)return node;
        if(small <= node->val && node->val <= big)return node;
        return node->val > big ? findAncestor(node->left) : findAncestor(node->right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        big = max(p->val, q->val);
        small = min(p->val, q->val);
        return findAncestor(root);
    }
};