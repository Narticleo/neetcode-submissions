class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }       

        vector<int> charCount(26, 0);
        int len = s.length();
        for(int i = 0; i < len; i++){
            charCount[s[i]-'a']++;
            charCount[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)
            if(charCount[i])
                return false;

        return true; 
    }
};
