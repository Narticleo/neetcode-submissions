class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for coin in coins:
            for number in range(coin, amount+1):
                dp[number] += dp[number - coin]
        return dp[amount]