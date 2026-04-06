class Solution {
private:
    void backtracking(vector<vector<int>>& result, vector<int>& nums, vector<int>& combination, int i, int target){
        if(target <=0 || i == nums.size()){
            if(target == 0)result.push_back(combination);
            return ;
        }
        int j = i;
        while(j+1 < nums.size() && nums[i] == nums[j+1])j++;
        int limit = min(target / nums[i], j - i + 1);
        if(limit == 0)return;
        for(int k = 0; k < limit; k++)combination.push_back(nums[i]);
        for(int k = limit; k >= 0; k--){
            // if(target - nums[i]*k >= nums[j+1])
            backtracking(result, nums, combination, j+1, target - nums[i]*k);
            if(k)combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums(candidates);
        vector<vector<int>> result;
        vector<int> combination;
        sort(nums.begin(), nums.end());      
        backtracking(result, nums, combination, 0, target);
        return result;  
    }
};


