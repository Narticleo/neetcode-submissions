class Solution {
private: 
    void palindrome(vector<vector<string>>& result, vector<string>& palins, string& str, int i){
        if(i == str.size()){
            result.push_back(palins);
            return ;
        }
        for(int j=i; j<str.size(); j++){
            if(isPalindrome(i, j, str)){
                palins.push_back(str.substr(i, j-i+1));
                palindrome(result, palins, str, j+1);
                palins.pop_back();
            }
        }
    }
    bool isPalindrome(int l, int r, string& str){
        while(l<r){
            if(str[l] != str[r])return false;
            l++; r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> palins;
        palindrome(result, palins, s, 0);
        return result;
    }
};
