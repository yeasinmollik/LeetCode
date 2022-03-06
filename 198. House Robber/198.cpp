/*
    Author: Yeasin Mollik
    Problem Name: House Robber
    Date: 6/3/2022
*/
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prevStolen = nums[0], prevNotStolen = 0, currStolen, currNotStolen;

        for (int i = 1; i < n; i++) {
            currStolen = prevNotStolen + nums[i];
            currNotStolen = max(prevStolen, prevNotStolen);

            prevStolen = currStolen;
            prevNotStolen = currNotStolen;
        }

        return max(prevStolen, prevNotStolen);
    }
};