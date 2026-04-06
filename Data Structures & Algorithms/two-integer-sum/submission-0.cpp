class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(umap.count(target - nums[i]))
                return vector<int>{umap[target - nums[i]], i};
            else
                umap[nums[i]] = i;
        }
        return vector<int>{0,0};   
    }
};
