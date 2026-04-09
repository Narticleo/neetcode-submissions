class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 2){
            if(n == 1)return cost[0];
            return min(cost[0], cost[1]);
        }
        vector<int> minCost(n+1, 0);
        for(int i=2; i<=n; i++)
            minCost[i] = min((minCost[i-1] + cost[i-1]), (minCost[i-2] + cost[i-2]));
        return minCost[n];
    }
};
