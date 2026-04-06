class Solution {
private:
    int maxLength = 0;
    int longestPath(TreeNode* node){
        if(node == nullptr)return 0;
        int rlen = longestPath(node->right);
        int llen = longestPath(node->left);
        maxLength = max(maxLength, rlen + llen);
        return max(rlen+1, llen+1);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longestPath(root);
        return maxLength;
    }
};