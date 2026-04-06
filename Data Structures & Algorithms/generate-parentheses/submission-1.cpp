#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    void backtracking(vector<string>& result, string& parenthesis, int left, int right){
        if(right < left || left < 0)return ;
        if(left == 0 && right == 0){
            result.push_back(parenthesis);
            return ;
        }
        parenthesis += '(';
        backtracking(result, parenthesis, left - 1, right);
        parenthesis.pop_back();

        parenthesis += ')';
        backtracking(result, parenthesis, left, right - 1);
        parenthesis.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string parenthesis;
        backtracking(result, parenthesis, n, n);
        return result;
    }
};