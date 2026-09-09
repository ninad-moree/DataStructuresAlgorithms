/*
    You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
    The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
    Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

    Example 1:
    Input: intervals = [[3,4],[2,3],[1,2]]
    Output: [-1,0,1]
    Explanation: There is no right interval for [3,4].
    The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
    The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<vector<int>, int>> sorted_intervals;
        for (int i = 0; i < n; ++i) 
            sorted_intervals.push_back({intervals[i], i});
        

        // Sort based on start points
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const auto& a, const auto& b) {
            return a.first[0] < b.first[0];
        });

        vector<int> result(n, -1);

        for (int i = 0; i < n; ++i) {
            int end = intervals[i][1];

            int left = 0, right = n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                int start = sorted_intervals[mid].first[0];

                if (start >= end) {
                    result[i] = sorted_intervals[mid].second; 
                    right = mid - 1;
                }
                else 
                    left = mid + 1;
            }
        }

        return result;
    }
};