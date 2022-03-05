/*
    Author: Yeasin Mollik
    Problem Name: 3Sum
    Date: 5/3/2022

*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if (sz < 3)
            return {};

        vector<vector<int>> ans;

        for (int i = 0; i < sz; i++) {
            // already found all the triplets(x <= y <= z) where x = nums[i] and x + y + z = 0. So, skip it.
            if (i && nums[i] == nums[i - 1])
                continue;

            // Using Two Sum II problem's approach to find all the pairs (y, z) such that  y + z = -nums[i]
            int low = i + 1, high = sz - 1, target = -nums[i];
            while (low < high) {
                int sum = nums[low] + nums[high];

                if (sum == target) {
                    ans.emplace_back(vector<int>{nums[i], nums[low], nums[high]});

                    while (low < high && nums[low] == nums[low + 1])  // skipping duplicates
                        low++;
                    while (low < high && nums[high] == nums[high - 1])  // skipping duplicates
                        high--;

                    low++, high--;
                } else if (sum < target)
                    low++;
                else
                    high--;
            }
        }

        return ans;
    }
};