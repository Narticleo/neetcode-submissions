class Solution {
private:
    bool isInWindow(int top, int i, int k){
        return top > i-k;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> result(n-k+1);

        for(int i=0; i<n; i++){
            while(!dq.empty() && nums[i]> nums[dq.back()])
                dq.pop_back();
            if(!dq.empty() && dq.front() < i-k+1)dq.pop_front();
            dq.push_back(i);
            if(i >= k-1)result[i-k+1] = nums[dq.front()];
        }
        return result;

    }
};