class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        while(nums[right] < nums[left]){
            int middle = (right + left) / 2;
            if(nums[middle] > nums[right])
                left = middle + 1;
            else
                right = middle;
        }

        return nums[left];
    }
};
