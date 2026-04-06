class Solution {
    int goodCounts = 0;
    void dfs(TreeNode* node, int pathMax){
        if(!node)return ;
        if(node->val >= pathMax)goodCounts++;
        pathMax = max(pathMax, node->val);
        dfs(node->left, max(pathMax, pathMax));
        dfs(node->right, max(pathMax, pathMax));
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return goodCounts;
    }
};