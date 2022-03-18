/*
    Author: Yeasin Mollik
    Problem Name: Longest Consecutive Sequence
    Date: 18/3/2022
*/

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0, n = nums.size();
        unordered_set<int> s;
        for (int x : nums)
            s.insert(x);

        for (int i = 0; i < n; i++) {
            if (exists(s, nums[i] - 1)) continue;

            int curr = nums[i];
            int currentStreak = 1;

            while (exists(s, curr + 1))
                curr++, currentStreak++;

            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak;
    }

    bool exists(unordered_set<int>& s, int x) {
        return s.find(x) != s.end();
    }
};