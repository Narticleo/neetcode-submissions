class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string str : strs)
            result += (to_string(str.length()) + '#' + str);
        return result;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int len = s.length();
        string strlen = "";
        int start = 0;
        while(start<len){
            int sign = s.find('#', start);
            int num = stoi(s.substr(start, sign-start));
            strs.push_back(s.substr(sign + 1, num));
            start = sign + num + 1;
        }            
        return strs;
    }
};