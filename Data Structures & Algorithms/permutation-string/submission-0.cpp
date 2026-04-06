class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int matches = 0;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        int n = s1.size();
        int m = s2.size();
        for(int i=0; i<n ; i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        for(int i=0; i<26; i++)
            if(v1[i] == v2[i])matches++;

        for(int i=1; i<m-n+1; i++){
            if(matches == 26)return true;
            int oldCh = s2[i-1] - 'a';
            int newCh = s2[i+n-1] - 'a';
            if(v1[oldCh] == v2[oldCh])matches--;
            if(v1[newCh] == v2[newCh])matches--;
            v2[oldCh]--;
            v2[newCh]++;
            if(v1[oldCh] == v2[oldCh])matches++;
            if(v1[newCh] == v2[newCh])matches++;
        }

        return matches == 26;
    }
};
