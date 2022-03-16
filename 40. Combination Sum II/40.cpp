/*
    Author: Yeasin Mollik
    Problem Name: Combination Sum II
    Date: 16/3/2022
*/

class Solution {
   public:
    int n, freq[51] = {};
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // count the frequency of distinct integers and then delete the duplicates
        for (int x : candidates)
            freq[x]++;
        candidates.clear();
        for (int i = 1; i <= 50; i++)
            if (freq[i]) candidates.emplace_back(i);
        n = candidates.size();

        vector<int> combination;
        vector<vector<int>> ans;
        getCombinations(candidates, target, 0, 0, combination, ans);

        return ans;
    }

    void getCombinations(vector<int> &candidates, int &target, int sum, int id, vector<int> &combination, vector<vector<int>> &ans) {
        if (sum > target)  // no point going any further, so backtrack from here
            return;

        if (sum == target) {  // found an eligible combination
            ans.emplace_back(combination);
            return;
        }

        // since sum < target, we try adding more element to the combination
        for (int i = id; i < n; i++) {
            int cand = candidates[i], fq = freq[candidates[i]];

            // this is done to avoid duplicate combination
            for (int j = 0; j < fq; j++) {
                if (sum + cand > target)
                    break;

                sum += cand;
                combination.emplace_back(cand);

                getCombinations(candidates, target, sum, i + 1, combination, ans);
            }

            while (!combination.empty() && combination.back() == cand) {
                sum -= cand;
                combination.pop_back();
            }
        }
    }
};