class Solution {
private:
    int maxSum = INT_MIN;
    int pathSum(TreeNode* node){
        if(!node)return 0;
        int left = pathSum(node->left);
        int right = pathSum(node->right);
        maxSum = max(maxSum, max(left,0) + max(right,0) + node->val);
        return node->val + max(max(left, right), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxSum;
    }
};
