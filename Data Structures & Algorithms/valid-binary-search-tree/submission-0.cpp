class Solution {
    bool dfs(TreeNode* node, long lower, long upper){
        if(!node)return true;
        if(node->val <= lower || node->val >= upper)return false;
        return dfs(node->left, lower, node->val) &&
                dfs(node->right, node->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};