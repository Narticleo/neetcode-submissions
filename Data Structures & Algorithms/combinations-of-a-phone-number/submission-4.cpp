class Solution {
private:
    void backtracking(vector<string>& result, vector<string>& hash, string& str, string& digits, int i){
        if(i == digits.size()){
            result.push_back(str);
            return;
        }

        for(char c : hash[digits[i]-'0'-2]){
            str += c;
            backtracking(result, hash, str, digits, i+1);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return {};
        vector<string> hash({"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
        vector<string> result;
        string str;
        backtracking(result, hash, str, digits, 0);
        return result;
    }
};