class Solution {
private:
    bool isInWindow(int top, int i, int k){
        return top > i-k;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> result(n-k+1);
        for(int i=0; i<k; i++)
            pq.push({nums[i], i});

        result[0] = pq.top().first;
        for(int i=k; i<n; i++){
            while(!pq.empty() && !isInWindow(pq.top().second, i, k))
                pq.pop();
            pq.push({nums[i], i});
            result[i-k+1] = pq.top().first;
        }

        return result;
    }
};
