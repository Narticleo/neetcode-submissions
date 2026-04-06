class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX; 
        int sizeNum = size(nums);
        for(int i=0 ; i<sizeNum; i++){
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }

        int capicity = maxVal - minVal + 1;
        vector<pair<int,int>> vec(capicity);
        for(int i=0; i<sizeNum; i++){
            vec[nums[i] - minVal].first = nums[i];
            vec[nums[i] - minVal].second++;
        }

        sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int,int> &b){return a.second > b.second;});
        vector<int> topK(k);
        for(int i=0; i<k; i++)
            topK[i] = vec[i].first;
        
        return topK;            
    }
};
