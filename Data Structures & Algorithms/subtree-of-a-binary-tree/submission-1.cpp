class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)return true;
        if(p == nullptr || q == nullptr)return false;
        if(p->val != q->val)return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root, subRoot))return true;
        return root? isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) : false;
    }
};