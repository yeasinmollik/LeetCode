/*
    Author: Yeasin Mollik
    Problem Name: Merge Intervals
    Date: 6/3/2022
*/

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        vector<vector<int>> ans;

        for (int i = 0; i < sz;) {
            int start = intervals[i][0], end = intervals[i][1];  // current interval

            // iterate over all intervals that overlaps with current interval (start, end)
            // and update the end point to farthest whenever possible
            while (++i < sz && intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }

            ans.emplace_back(vector<int>{start, end});
        }

        return ans;
    }
};