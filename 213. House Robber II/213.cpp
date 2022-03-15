/*
    Author: Yeasin Mollik
    Problem Name: House Robber II
    Date: 15/3/2022
*/

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }

    // Solution from House Robber problem
    int robHelper(vector<int>& nums, int l, int r) {
        int robbed = nums[l], notRobbed = 0;

        for (int i = l + 1; i <= r; i++) {
            int currRobbed = notRobbed + nums[i];
            int currNotRobbed = max(robbed, notRobbed);

            robbed = currRobbed;
            notRobbed = currNotRobbed;
        }

        return max(robbed, notRobbed);
    }
};