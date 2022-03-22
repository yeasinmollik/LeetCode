/*
    Author: Yeasin Mollik
    Problem Name: Decode Ways
    Date: 21/3/2022
*/

class Solution {
   public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;

        int n = s.size();
        int prev = 1, prevPrev = 1, curr;

        for (int i = 2; i <= n; i++) {
            int oneDigit = s[i - 1] - '0', twoDigit = stoi(s.substr(i - 2, 2));

            // s[i] can't be mapped to any character for this case
            if (oneDigit == 0 && twoDigit != 10 && twoDigit != 20) return 0;

            curr = 0;
            // s[i] can be used as a single-digit number for decoding
            if (oneDigit > 0)
                curr += prev;
            // s[i] can be used as a part of a double-digit number for decoding
            if (twoDigit >= 10 && twoDigit <= 26)
                curr += prevPrev;

            prevPrev = prev;
            prev = curr;
        }

        return curr;
    }
};
