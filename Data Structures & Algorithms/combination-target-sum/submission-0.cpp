class Solution {
private:
    void slove(vector<int>& nums, vector<vector<int>>& result, vector<int>& combination, int s, int target){
        if(s == nums.size() || target <= 0) {
            if(target == 0)result.push_back(combination);
            return;
        }
        for(int i = s; i < nums.size(); i++){
            if(target - nums[i] < 0)return;
            combination.push_back(nums[i]);
            slove(nums, result, combination, i, target-nums[i]);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums(candidates);
        vector<vector<int>> result;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        slove(nums, result, combination, 0, target);
        return result;
    }
};
