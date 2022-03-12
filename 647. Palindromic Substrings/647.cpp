/*
    Author: Yeasin Mollik
    Problem Name: Palindromic Substrings
    Date: 12/3/2022
*/

class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        // counts number of palindromes having s[i] as the middle element for all i
        for (int i = 0; i < n; i++) {
            ans += countPal(s, i, i);      // counts odd sized palindrome
            ans += countPal(s, i, i + 1);  // counts even sized palindrome
        }

        return ans;
    }

    int countPal(string &s, int l, int r) {
        int count = 0;

        while (l >= 0 && r < s.size() && s[l] == s[r])
            count++, l--, r++;

        return count;
    }
};