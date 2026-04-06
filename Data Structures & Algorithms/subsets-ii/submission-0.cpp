#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
private:
    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation, int i){
        if(i == nums.size()){
            result.push_back(permutation);
            return ;
        }
        int j = i;
        while(j+1 < nums.size() && nums[j+1] == nums[i])j++;
        int len = j - i + 1;
        for(int k = 0; k < len; k++)permutation.push_back(nums[i]);
        for(int k = len; k >= 0; k--){
            backtracking(nums, result, permutation, j+1);
            if(k)permutation.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> permutation;
        backtracking(nums, result, permutation, 0);
        return result;
    }
};