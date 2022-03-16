/*
    Author: Yeasin Mollik
    Problem Name: Combination Sum III
    Date: 16/3/2022
*/

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combination;

        getCombinations(0, n, 1, k, combination, ans);
        return ans;
    }

    void getCombinations(int sum, int &n, int curr, int &k, vector<int> &combination, vector<vector<int>> &ans) {
        if (combination.size() > k || sum > n)  // going further won't give any solution, so backtrack
            return;

        if (combination.size() == k) {
            if (sum == n)  // found an eligible combination 
                ans.emplace_back(combination);

            return;
        }

        for (int i = curr; i <= 9; i++) {
            sum += i;
            combination.emplace_back(i);

            getCombinations(sum, n, i + 1, k, combination, ans);

            // undoing changes and moving to the next option
            sum -= i;
            combination.pop_back();
        }
    }
};
