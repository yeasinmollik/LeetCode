/*
    Author: Yeasin Mollik
    Problem Name: Contains Duplicate
    Date: 18/3/2022
*/

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;

        for (int x : nums) {
            if (m[x])
                return true;
            else
                m[x] = true;
        }
        
        return false;
    }
};