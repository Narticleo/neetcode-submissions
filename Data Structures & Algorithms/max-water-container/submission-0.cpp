class Solution {
private:
    int getArea(int x1, int y1, int x2, int y2){
        int height = min(y1, y2);
        return (x2-x1)*height;
    }
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left < right){
            int area = getArea(left, height[left], right, height[right]);
            maxArea = max(maxArea, area);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};