class Solution {
public:
    int trap(vector<int>& height) {
        int left, maxLeft, maxRight, water;
        left = maxLeft = maxRight = water = 0;
        int right = height.size()-1;
        while(left<right){
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            if(maxLeft < maxRight)water += (maxLeft - height[left++]);
            else water += (maxRight - height[right--]);
        }
        return water;
    }
};