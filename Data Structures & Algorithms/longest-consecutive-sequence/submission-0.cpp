class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int longest = 0;
        for(int num : uset){
            int start = num;
            int len = 1;
            if(!uset.count(num-1)){
                while(uset.count(start+1)){
                    len++;
                    start++;
                }
            }
            longest = max(longest, len);
        }
        return longest;
    }
};