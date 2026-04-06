class Solution {
    int maxDepth = 0;
    vector<int> rightSideVals;
    void dfs(TreeNode* node, int depth){
        if(node == nullptr)return;
        if(depth > maxDepth)rightSideVals.push_back(node->val);
        maxDepth = max(depth, maxDepth);
        dfs(node->right, depth+1);
        dfs(node->left, depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return rightSideVals;
    }
};