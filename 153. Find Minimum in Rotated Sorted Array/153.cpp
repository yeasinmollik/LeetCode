/*
    Author: Yeasin Mollik
    Problem Name: Find Minimum in Rotated Sorted Array
    Date: 20/3/2022
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        if (nums[0] <= nums.back())  // array is already sorted
            return nums[0];

        int l = 0, r = nums.size() - 1, max;

        // find the greatest number in the array using binary search
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= nums[0])
                l = m + 1, max = m;
            else
                r = m - 1;
        }
        // Since the array is sorted, number next to the maximum number must be the minumum number
        return nums[max + 1];
    }
};