class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int wordLen = 0;
        int ss = s.size();
        int ds = wordDict.size();
        vector<bool> isValid(ss+1, false);
        unordered_set<string> dict;
        for(string& word : wordDict){
            dict.insert(word);
            wordLen = max(wordLen, int(word.size()));
        }        
        isValid[0] = true;
        for(int i=1; i<=ss; i++){
            for(string& word : wordDict){
                int pre = i - word.size();
                if(pre >= 0 && isValid[pre] && s.substr(pre, word.size()) == word)
                    isValid[i] = true;
            }
        }
        return isValid[ss];
    }
};