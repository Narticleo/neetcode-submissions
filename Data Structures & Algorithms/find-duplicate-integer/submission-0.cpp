class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(nums[i]){
            int number = nums[i];
            nums[i] = 0;
            i = number;
        }
        return i;
    }
};
