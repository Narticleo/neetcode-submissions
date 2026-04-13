using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int inorder = 0;
        int reverse = 0;
        int maxP = nums[0];
        for(int i=0; i<nums.size(); i++){
            inorder = nums[i] * (inorder? inorder : 1);
            reverse = nums[nums.size()-1-i] * (reverse? reverse : 1);
            maxP = max(maxP, max(inorder, reverse));
        }
        return maxP;
    }
};
