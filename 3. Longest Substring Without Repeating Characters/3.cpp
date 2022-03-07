/*
    Author: Yeasin Mollik
    Problem Name: Longest Substring Without Repeating Characters
    Date: 7/3/2022
*/

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> lastIndex(128, -1);
        lastIndex[s[0]] = 0;

        int prevLongest = 1, ans = 1, currLongest;

        for (int i = 1; i < n; i++) {
            currLongest = min(prevLongest + 1, i - lastIndex[s[i]]);
            ans = max(ans, currLongest);

            prevLongest = currLongest;
            lastIndex[s[i]] = i;
        }

        return ans;
    }
};