/*
    Author: Yeasin Mollik
    Problem Name: Longest Repeating Character Replacement
    Date: 7/3/2022
*/

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;

        bool have[91] = {};
        for (char &ch : s) have[ch] = true;

        for (char c = 'A'; c <= 'Z'; c++) {
            if (!have[c])
                continue;

            // cnt keeps track of the frequency of c in the range [left, right]
            int left = 0, right = 0, cnt = 0;
            while (right < n) {
                if (s[right] == c)
                    cnt++;

                while (left <= right && (cnt + k < right - left + 1)) {
                    if (s[left] == c)
                        cnt--;
                    left++;
                }
                ans = max(ans, right - left + 1);
                right++;
            }
        }

        return ans;
    }
};