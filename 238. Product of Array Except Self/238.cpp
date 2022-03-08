/*
    Author: Yeasin Mollik
    Problem Name: Product of Array Except Self
    Date: 8/3/2022
*/

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefixProduct = 1, suffixProduct = 1;
        vector<int> ans(n, 1);

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            ans[i] *= prefixProduct;
            prefixProduct *= nums[i];

            ans[j] *= suffixProduct;
            suffixProduct *= nums[j];
        }

        return ans;
    }
};