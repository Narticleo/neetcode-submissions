class Solution {
private:
    bool isOperator(string str){
        return str == "+" || str == "-" ||
                str == "*" || str == "/";
    }

    int popAndReturn(stack<int> &postfix){
        int number = postfix.top();
        postfix.pop();
        return number;
    }

    int evaluate(string symbol, int op1, int op2){
        char c = symbol[0];
        switch(c){
            case('+'):
                return op1 + op2;
            case('-'):
                return op1 - op2;
            case('*'):
                return op1 * op2;
            case('/'):
                return op1 / op2; 
        };
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> postfix;
        for(string token : tokens){
            if(isOperator(token)){
                int op2 = popAndReturn(postfix);
                int op1 = popAndReturn(postfix);
                postfix.push(evaluate(token, op1, op2));
            }else
                postfix.push(stoi(token));
        }
        return postfix.top();
    }
};