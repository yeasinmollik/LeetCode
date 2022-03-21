/*
    Author: Yeasin Mollik
    Problem Name: Insert Interval
    Date: 20/3/2022
*/

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), inserted = 0;
        vector<vector<int>> ans;

        int i = 0;
        while (i < n) {
            if (!overlap(intervals[i], newInterval))
                ans.emplace_back(intervals[i++]);
            else {
                while (i < n && overlap(intervals[i], newInterval)) {
                    newInterval[0] = min(intervals[i][0], newInterval[0]);  // updating the start of newInterval
                    newInterval[1] = max(intervals[i][1], newInterval[1]);  // updating the end of newInterval
                    i++;
                }
                ans.emplace_back(newInterval);
                inserted = 1;
            }
        }
        // for the case where no interval overlaps with newInterval and as a result newInterval wasn't inserted
        if (!inserted)
            ans.insert(upper_bound(ans.begin(), ans.end(), newInterval), newInterval);

        return ans;
    }
    bool overlap(vector<int>& a, vector<int>& b) {
        return !(a[0] > b[1] || a[1] < b[0]);
    }
};