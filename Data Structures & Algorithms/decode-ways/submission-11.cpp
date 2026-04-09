class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0')return 0;
        if(n == 1)return 1;
        if(s[1] == '0' && s[0] > '2')return 0;
        vector<int> ways(n, 0);
        
        ways[0] = 1; 
        ways[1] = s[1] == '0' || s[1] > '6' ? 1 : 2;

        for(int i=2; i<n; i++){
            int pre = s[i-1] - '0';
            int cur = s[i] - '0';
            if(pre == 1 || (pre == 2 && cur <= 6)){
                if(cur == 0)ways[i] = ways[i-2];
                else ways[i] = ways[i-1] + ways[i-2];
            }else{
                if(cur == 0)return 0;
                ways[i] = ways[i-1];
            }
        }
        return ways[n-1];
    }
};
