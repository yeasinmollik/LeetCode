/*
    Author: Yeasin Mollik
    Problem Name: Decode Ways
    Date: 27/3/2022
*/

class Solution {
   public:
    int climbStairs(int n) {
        int dp[50] = {};
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};