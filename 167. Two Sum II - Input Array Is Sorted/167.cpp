class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int low = 0, high = numbers.size() - 1;

        while (low < high) {
            int sum = numbers[low] + numbers[high];

            if (sum == target) {
                ans.emplace_back(low + 1);
                ans.emplace_back(high + 1);
                break;
            } else if (sum < target)
                low++;
            else
                high--;
        }

        return ans;
    }
};