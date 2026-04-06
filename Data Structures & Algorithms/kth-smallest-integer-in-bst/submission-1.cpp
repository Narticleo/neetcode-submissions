class Solution {
private:
    int kthSmall = -1;
    int kthSmallVal = -1;
    int dfs(TreeNode* node, int smallerAbove){
        if(node == nullptr)return 0;
        int smallerBelow = dfs(node->left, 0);
        int smaller = smallerAbove + smallerBelow;
        if(smaller == kthSmall - 1)kthSmallVal = node->val;
        int bigger = dfs(node->right, smaller + 1);
        return smallerBelow + bigger + 1;
    }
    // int nodes(TreeNode* node){
    //     if(!node)return 0;
    //     return nodes(node->left) + nodes(node->right) + 1;
    // }
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmall = k;
        dfs(root, 0);
        return kthSmallVal;
    }
};