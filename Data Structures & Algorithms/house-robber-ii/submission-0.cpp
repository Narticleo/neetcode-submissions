class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        vector<int> planA(n-1, 0), planB(n-1, 0); //A skip first house, B ignore last house.
        
        planA[0] = nums[1]; planA[1] = max(nums[1], nums[2]);
        planB[0] = nums[0]; planB[1] = max(nums[0], nums[1]);

        for(int i=2; i<n-1; i++){
            planA[i] = max(planA[i-1], planA[i-2] + nums[i+1]);
            planB[i] = max(planB[i-1], planB[i-2] + nums[i]);
        }

        return max(planA[n-2], planB[n-2]);    
    }
};