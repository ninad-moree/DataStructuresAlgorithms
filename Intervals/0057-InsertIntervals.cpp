/*
    You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent 
    the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also 
    given an interval newInterval = [start, end] that represents the start and end of another interval.
    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals 
    still does not have any overlapping intervals (merge overlapping intervals if necessary).
    Return intervals after the insertion.

    Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};