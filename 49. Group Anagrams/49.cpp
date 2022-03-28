/*
    Author: Yeasin Mollik
    Problem Name: Group Anagrams
    Date: 28/3/2022
*/

class Solution {
   public:
    int p = 31, mod = 1e9 + 7;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++)
            hash[getHash(strs[i])].emplace_back(strs[i]);
        vector<vector<string>> ans;
        for (auto& x : hash)
            ans.emplace_back(x.second);
        return ans;
    }

    int getHash(string s) {
        sort(s.begin(), s.end());
        int hash = 0;
        long long p_exp = 1;
        for (char& c : s) {
            hash = (hash + (c - 'a' + 1) * p_exp) % mod;
            p_exp = (p_exp * p) % mod;
        }
        return hash;
    }
};
