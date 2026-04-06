class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indices;
        vector<int> result(temperatures.size(), 0);
        for(int i=0; i<result.size(); i++){
            while(!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                result[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }
        return result;
    }
};