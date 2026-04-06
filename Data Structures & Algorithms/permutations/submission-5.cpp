#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
private:
    void backtracking(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& permutation, vector<bool> pos, int i){
        if(i == nums.size()){
            permutations.push_back(permutation);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(pos[j] == false)continue;
            permutation[j] = nums[i];
            pos[j] = false;
            backtracking(nums, permutations, permutation, pos, i+1);
            pos[j] = true;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation(nums.size());
        vector<bool> pos(nums.size(), true);
        backtracking(nums, permutations, permutation, pos, 0);
        return permutations;
    }
};