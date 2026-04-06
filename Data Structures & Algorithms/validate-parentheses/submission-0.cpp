class Solution {
private:
    bool isLeft(char c){
        return c == '[' || c == '(' || c == '{';
    }
    bool isPair(char left, char right){
        return (left == '[' && right == ']') ||
                (left == '(' && right == ')') ||
                (left == '{' && right == '}');
    }
public:
    bool isValid(string s) {
        stack<char> parenthese;
        for(int i=0; i<s.size(); i++){
            if(isLeft(s[i]))
                parenthese.push(s[i]);
            else{
                if(parenthese.empty()) return false;
                char left = parenthese.top();
                parenthese.pop();
                if(!isPair(left, s[i]))
                    return false;
            }
        }
        return parenthese.empty();
    }
};