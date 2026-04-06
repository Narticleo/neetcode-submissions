class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> level;
        vector<int> rightSide;
        if(root)level.push(root);
        while(!level.empty()){
            int nodeNum = level.size();
            while(nodeNum--){
                TreeNode* cur = level.front();
                if(!nodeNum)rightSide.push_back(cur->val);
                if(cur->left)level.push(cur->left);
                if(cur->right)level.push(cur->right);
                level.pop();
            }
        }
        return rightSide;
    }
};