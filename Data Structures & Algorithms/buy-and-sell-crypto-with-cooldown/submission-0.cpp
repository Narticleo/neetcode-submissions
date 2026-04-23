class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n)return 0;
        int buy = -1 * prices[0];
        int sell = 0;
        int wait = 0;
        for(int day=1; day<n; day++){
            int buy_pre = buy, sell_prev = sell, wait_prev = wait;
            buy = max(buy_pre, wait-prices[day]);
            sell = buy_pre + prices[day];
            wait = max(wait_prev, sell_prev);
        }
        return max(sell, wait);
    }
};
