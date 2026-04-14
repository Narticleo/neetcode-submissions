class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)return false;
        sort(nums.begin(), nums.end());
        int max = *(nums.end()-1);
        nums.pop_back();

        int target = sum/2 - max;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(int& num : nums){
            for(int i=target; i>=num; i--)
                dp[i] = dp[i-num] || dp[i];
            if(dp[target])return true;
        }

        return dp[target];
    }
};
