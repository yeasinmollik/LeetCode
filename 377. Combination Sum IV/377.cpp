/*
    Author: Yeasin Mollik
    Problem Name: Combination Sum IV
    Date: 17/3/2022
*/

class Solution {
   public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n && nums[j] <= i; j++) {
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};