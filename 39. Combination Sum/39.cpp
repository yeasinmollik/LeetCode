/*
    Author: Yeasin Mollik
    Problem Name: Combination Sum
    Date: 14/3/2022
*/

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        getCombinations(ans, temp, candidates, 0, 0, target);

        return ans;
    }

    void getCombinations(vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidates, int id, int sum, int target) {
        if (sum > target)  // Bactracing from here bacause moving further won't lead to any solution
            return;
        if (sum == target) {  // Sum equals to target! So, adding current combination to the answer.
            ans.emplace_back(temp);
            return;
        }
        for (int i = id; i < candidates.size(); i++) {
            sum += candidates[i];
            temp.emplace_back(candidates[i]);  // adding candidates[i] to current combination

            getCombinations(ans, temp, candidates, i, sum, target);  // Continuing with this combination, whether it gives a solution or not.

            sum -= candidates[i];
            temp.pop_back();  // backtracking and moving to the next candidate
        }
    }
}