class MinStack {
private:
    stack<pair<int,int>> numbers;
    int minimum;
    void updateMin(){
        if(numbers.top().first == minimum)
            minimum = numbers.top().second;
    }
public:
    MinStack() {
        minimum = __INT_MAX__;
    }
    
    void push(int val) {
        int minExceptSelf = minimum;
        minimum = min(minimum, val);
        numbers.push({val, minExceptSelf});
    }
    
    void pop() {
        updateMin();
        numbers.pop();
    }

    int top() {
        return numbers.top().first;
    }
    
    int getMin() {        
        return numbers.empty()? 0 : minimum;
    }
};
