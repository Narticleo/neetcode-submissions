class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int n = s.size();
        int longest = 0;
        unordered_map<char, int> characters;
        while(start<n){
            int end = start;
            while(end<n && !characters.count(s[end])){
                characters[s[end]] = end;
                end++;
            }
            longest = max(end - start, longest);
            if(end>=n)break;
            start = characters[s[end]] + 1;
            characters.clear();
        }
        return longest;
    }
};
