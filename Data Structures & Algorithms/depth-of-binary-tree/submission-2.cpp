/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int deepest=0;
    void measureDepth(TreeNode* trNode, int depth){
        if(trNode == nullptr){
            deepest = max(deepest, depth);
            return;
        }
        measureDepth(trNode->right, depth+1);
        measureDepth(trNode->left, depth+1);
    }
public:
    int maxDepth(TreeNode* root) {
        measureDepth(root, 0);
        return deepest;
    }
};
