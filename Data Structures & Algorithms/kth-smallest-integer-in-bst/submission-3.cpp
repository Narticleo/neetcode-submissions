class Solution {
private:
    TreeNode* dfs(TreeNode* node, int &k){
        if(node == nullptr)return nullptr;
        TreeNode* left = dfs(node->left, k);
        if(left)return left;
        k--;
        if(!k)return node;
        return dfs(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k)->val;
    }
};