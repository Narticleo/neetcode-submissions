class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(i!=0 && nums[i-1]==nums[i])continue;
            if(nums[i]>0)break;
            int left = i+1;
            int right = len-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum<0)
                    left++;
                else if(sum>0)
                    right--;
                else{
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(left<right && nums[left] == nums[left-1])left++;
                    while(right>left && nums[right] == nums[right+1])right--;
                }   
            }
        }
        return triplets;
    }
};