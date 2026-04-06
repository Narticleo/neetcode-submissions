class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        while(right>left){
            if(!isalnum(s[right]))
                right--;
            else if(!isalnum(s[left]))
                left++;
            else{
                if(tolower(s[right]) != tolower(s[left]))
                    return false;
                left++;
                right--;
            }
        }
        return true;
    }
};