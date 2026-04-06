class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& results, vector<int>& subset, int i){
        if(i >= nums.size()){
            results.push_back(subset);
            return ;
        }
        subset.push_back(nums[i]);
        dfs(nums, results, subset, i+1);
        subset.pop_back();
        dfs(nums, results, subset, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> subset;
        dfs(nums, results, subset, 0);
        return results;
    }
};
