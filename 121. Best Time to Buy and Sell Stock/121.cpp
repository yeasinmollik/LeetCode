/*
    Author: Yeasin Mollik
    Problem Name: Best Time to Buy and Sell Stock
    Date: 28/3/2022
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minSoFar = prices[0];

        for (int x : prices) {
            maxProfit = max(maxProfit, x - minSoFar);
            minSoFar = min(minSoFar, x);
        }

        return maxProfit;
    }
};
