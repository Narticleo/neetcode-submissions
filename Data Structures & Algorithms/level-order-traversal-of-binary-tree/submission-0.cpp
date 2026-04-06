class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> orders;
        queue<TreeNode*> level;
        if(root)level.push(root);
        while(!level.empty()){
            int nodeNums = level.size();
            vector<int> levelNodes(nodeNums);
            for(int i=0; i<nodeNums; i++){
                TreeNode* cur = level.front();
                level.pop();
                levelNodes[i] = cur->val;
                if(cur->left)level.push(cur->left);
                if(cur->right)level.push(cur->right);
            }
            orders.push_back(levelNodes);
        }
        return orders;
    }
};