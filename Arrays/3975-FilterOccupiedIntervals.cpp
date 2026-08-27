/*
    You are given a 2D integer array occupiedIntervals, where occupiedIntervals[i] = [starti, endi] represents a time interval during which you are occupied. Each interval 
    starts at starti and ends at endi, inclusive. These intervals may overlap. You are also given two integers freeStart and freeEnd, which define a free time interval from 
    freeStart to freeEnd, inclusive. Your task is to merge all occupied intervals that overlap or touch, then remove all integer points in the free interval from the merged 
    occupied intervals. Two intervals touch if the second interval starts immediately after the first one ends. For example, [1, 1] and [2, 2] touch and should be merged into 
    [1, 2]. Return the remaining occupied intervals in sorted order. The returned intervals must be non-overlapping and must contain the minimum number of intervals possible. 
    If there are no remaining occupied points, return an empty list.

    Example 1:
    Input: occupiedIntervals = [[2,6],[4,8],[10,10],[10,12],[14,16]], freeStart = 7, freeEnd = 11
    Output: [[2,6],[12,12],[14,16]]
    Explanation: After merging, the occupied intervals are [2, 8], [10, 12], and [14, 16]. Excluding the free interval [7, 11] results in [2, 6], [12, 12], and [14, 16].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;
        merged.push_back(occupiedIntervals[0]);

        for(int i=1; i<occupiedIntervals.size(); i++) {
            int prevEnd = merged.back()[1];
            int currSt = occupiedIntervals[i][0];
            int currEnd = occupiedIntervals[i][1];

            if(prevEnd >= currSt-1) 
                merged.back()[1] = max(currEnd, prevEnd);
            else
                merged.push_back(occupiedIntervals[i]);
        }

        vector<vector<int>> ans;

        for(int i=0; i<merged.size(); i++) {
            int currStart = merged[i][0];
            int currEnd = merged[i][1];

            if(currStart > freeEnd || currEnd < freeStart) {
                ans.push_back(merged[i]);
                continue;
            }

            if(currStart < freeStart) 
                ans.push_back({currStart, freeStart-1});

            if(currEnd > freeEnd)
                ans.push_back({freeEnd+1, currEnd});
        }

        return ans;
    }
};