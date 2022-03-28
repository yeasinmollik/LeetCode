 /*
    Author: Yeasin Mollik
    Problem Name: Top K Frequent Elements
    Date: 28/3/2022
*/

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int& x : nums) freq[x]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& x : freq) bucket[x.second].emplace_back(x.first);

        vector<int> ans;
        for (int i = nums.size(); i >= 1 && k; i--) {
            for (int j = 0; j < bucket[i].size() && k; j++) {
                ans.emplace_back(bucket[i][j]);
                k--;
            }
        }
        return ans;
    }
};
