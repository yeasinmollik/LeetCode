/*
    Author: Yeasin Mollik
    Problem Name: Valid Anagram
    Date: 28/3/2022
*/

class Solution {
   public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {};
        for (char &c : s) cnt[c - 'a']++;
        for (char &c : t) cnt[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (cnt[i] != 0) return false;
        return true;
    }
};
