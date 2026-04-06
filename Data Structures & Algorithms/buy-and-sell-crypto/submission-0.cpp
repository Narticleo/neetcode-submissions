class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int sold = prices[1];
        int maxProfit = 0;
        for(int i=1; i<n; i++){
            int sold = prices[i];
            int profit = sold - buy; 
            maxProfit = max(maxProfit, profit);
            buy = min(buy, sold);
        }
        return maxProfit;
    }
};