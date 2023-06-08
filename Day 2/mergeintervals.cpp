//https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <iostream>
#include <vector>
#include <algorithm>

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    if (intervals.empty()) {
        return {};
    }

    // Sort the intervals based on their start points
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        vector<int>& currInterval = intervals[i];
        vector<int>& prevInterval = mergedIntervals.back();

        if (currInterval[0] <= prevInterval[1]) {
            // Overlapping or can be merged, update the end point of the previous interval
            prevInterval[1] = max(prevInterval[1], currInterval[1]);
        } else {
            // Non-overlapping, add the current interval as a new interval
            mergedIntervals.push_back(currInterval);
        }
    }

    return mergedIntervals;
}
