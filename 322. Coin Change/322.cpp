/*
    Author: Yeasin Mollik
    Problem Name: Coin Change
    Date: 4/4/2022
*/

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), infinity = 1e9;
        vector<int> dp(amount + 1, infinity);
        dp[0] = 0;  // base case

        for (int i = 1; i <= n; i++) {
            int coin = coins[i - 1];
            for (int j = 0; j <= amount; j++) {
                int curr = dp[j];
                if (coin <= j)
                    curr = min(curr, dp[j - coin] + 1);
                dp[j] = curr;
            }
        }

        if (dp[amount] == infinity)
            return -1;
        else
            return dp[amount];
    }
};
