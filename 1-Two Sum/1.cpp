class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        unordered_map<int, int> indexOf;

        vector<int> ans;
        for (size_t i = 0; i < sz; i++) {
            int needed = target - nums[i];

            if (indexOf.count(needed)) {  // checks if needed exist in the map or not
                ans.push_back(indexOf[needed]);
                ans.push_back(i);
                break;
            }
            indexOf[nums[i]] = i;
        }
        return ans;
    }
};