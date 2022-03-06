/*
    Author: Yeasin Mollik
    Problem Name: Non-overlapping Intervals
    Date: 6/3/2022
*/

class Solution {
   public:
    // custom comparator to sort intervals according to increasing ending value
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[1] != b[1])
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int selected = 1, total = intervals.size();
        auto lastSelected = intervals[0];

        for (int i = 1; i < total; i++) {
            // if intervals[i] doesn't overlap with lastSelected, add it to selected list and update lastSelected.
            if (intervals[i][0] >= lastSelected[1])
                selected++, lastSelected = intervals[i];
        }

        int removed = total - selected;
        return removed;
    }
};