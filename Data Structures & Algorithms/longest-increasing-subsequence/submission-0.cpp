class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increasing;
        increasing.push_back(nums[0]);
        for(int& num : nums){
            if(num > increasing.back())
                increasing.push_back(num);
            else{
                auto it = lower_bound(increasing.begin(), increasing.end(), num);
                int replace = it - increasing.begin();
                increasing[replace] = num;
            }
        }
        return increasing.size();
    }
};
