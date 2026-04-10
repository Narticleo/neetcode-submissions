class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = INT_MAX;
        vector<int> minCoin(amount+1, inf);
        minCoin[0] = 0;
        for(int& coin : coins){
            for(int i=coin; i<=amount; i++){
                if(minCoin[i-coin] != inf)
                    minCoin[i] = min(minCoin[i], 1 + minCoin[i-coin]);
            }
        }        
        return minCoin[amount] == inf ? -1 : minCoin[amount];
    }
};
