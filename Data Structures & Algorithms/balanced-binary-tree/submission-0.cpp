class Solution {
    bool balanced = true;
    int length(TreeNode* node){
        if(node == nullptr)return 0;
        int rlen = length(node->right);
        int llen = length(node->left);
        balanced = balanced && abs(rlen - llen) <= 1;
        return max(rlen+1, llen+1);
    }
public:
    bool isBalanced(TreeNode* root) {
        length(root);
        return balanced;
    }
};