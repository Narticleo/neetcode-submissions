class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1;
        vector<int>& b = nums2;
        if(a.size() > b.size())swap(a, b);

        int total = a.size() + b.size();
        int half = (total + 1) / 2;
        int left = 0; int right = a.size();
        while(left <= right){
            int aMid = (left + right) / 2;
            int bMid =  half - aMid;
            int aLeft = aMid > 0? a[aMid - 1] : INT_MIN;
            int aRight = aMid < a.size()? a[aMid] : INT_MAX; 
            int bLeft = bMid > 0? b[bMid - 1] : INT_MIN;
            int bRight = bMid < b.size()? b[bMid] : INT_MAX;
            if(bRight >= aLeft && aRight >= bLeft){
                if(total % 2)return max(aLeft, bLeft);
                return (float)(max(aLeft, bLeft) + min(aRight, bRight)) / 2;
            }else if(aLeft > bRight){
                right = aMid - 1;
            }else{
                left = aMid + 1;
            }
        }
        return -1;
    }
};
