class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        int zero = -1;
        stack<int> limit;
        if(heights[0])limit.push(0);
        for(int i=1; i<n; i++){
            if(!heights[i-1])zero = i-1;
            while(!limit.empty() && heights[limit.top()] > heights[i]){
                int height = heights[limit.top()]; limit.pop();
                int leftBound = limit.empty()? zero : limit.top();
                int rightBound = i;
                int area = (rightBound - leftBound - 1) * height;
                maxArea = max(area, maxArea);
            }
            if(heights[i])
                limit.push(i);
        }
        while(!limit.empty()){
            int height = heights[limit.top()]; limit.pop();
            int leftBound = limit.empty()? zero : limit.top();
            int rightBound = n;
            int area = (rightBound - leftBound - 1) * height;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
