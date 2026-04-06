class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size()-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] > nums[r])
                l = m + 1;
            else
                r = m;
        }

        if(target <= nums[nums.size() - 1])
            r = nums.size()-1;
        else{   l = 0;  r -= 1; }

        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target)return m;
            if(target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};