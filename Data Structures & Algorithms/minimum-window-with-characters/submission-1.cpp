class Solution {
private:
    int index(char ch){
        if(isupper(ch))return ch - 'A' + 26;
        return ch - 'a';
    }
public:
    string minWindow(string s, string t) {
        vector<int> vs(52, 0);
        vector<int> vt(52, 0);
        int ss = s.size();
        int ts = t.size();
        int letters = 0;
        int biggerEqual = 0;
        int minLen = ss;
        string minStr = "";
        if(ss<ts)return "";

        for(int i=0; i<ts; i++){
            if(vt[index(t[i])] == 0)letters++;
            vt[index(t[i])]++;
        }

        
        int left = 0;
        for(int right=0; right<ss; right++){
            int ri = index(s[right]);
            vs[ri]++;
            if(vs[ri] == vt[ri])biggerEqual++;
            if(biggerEqual == letters){
                while(biggerEqual == letters){
                    int li = index(s[left++]);
                    vs[li]--;
                    if(vs[li] < vt[li])biggerEqual--;
                }
                if(right-left+2 <= minLen){
                    minLen = right-left+2;
                    minStr = s.substr(left-1, minLen);
                }
            }
        }

        return minStr;
    }
};
