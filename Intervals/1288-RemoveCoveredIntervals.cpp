/*
    Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
    remove all intervals that are covered by another interval in the list.
    The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
    Return the number of remaining intervals.

    Example 1:
    Input: intervals = [[1,4],[3,6],[2,8]]
    Output: 2
    Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Sort in descending order of end points
            }
            return a[0] < b[0]; // Sort in ascending order of start points
        });

        int cnt = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][1] <= end)
                cnt++;
            else
                end = intervals[i][1];
        }

        return intervals.size() - cnt;
    }
};