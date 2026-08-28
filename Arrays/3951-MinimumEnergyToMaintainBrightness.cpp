/*
    You are given an integer n, representing n light bulbs arranged in a line and indexed from 0 to n - 1. You are also given an integer brightness and a 2D integer array 
    intervals, where intervals[i] = [starti, endi] represents an inclusive time interval during which the lighting requirement must be satisfied. At each time unit, every bulb 
    can independently be either on or off. A bulb that is on illuminates its own position and its adjacent positions, if they exist. The total illumination at a time unit is 
    the number of illuminated positions. Each position is counted at most once. For every integer time unit covered by at least one interval in intervals, the total 
    illumination must be at least brightness. At time units not covered by any interval, all bulbs may remain off. Each bulb that is on consumes 1 unit of energy for that time 
    unit. Return an integer denoting the minimum total energy required.

    Example 1:
    Input: n = 5, brightness = 5, intervals = [[6,12]]
    Output: 14
    Explanation: Turn on the light bulbs at positions 1 and 4. Current state of line: 0 1 0 0 1. All 5 positions are illuminated, so the required brightness is reached.
    The active interval has length 12 - 6 + 1 = 7, so the total energy is 2 * 7 = 14.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
            int prevEnd = merged.back()[1];
            int currSt = intervals[i][0];
            int currEnd = intervals[i][1];

            if(prevEnd >= currSt-1) 
                merged.back()[1] = max(currEnd, prevEnd);
            else
                merged.push_back(intervals[i]);
        }

        long long len = 0;

        for(auto i : merged) {
            int st = i[0];
            int end = i[1];

            len += (end - st + 1);
        }

        long long need = (brightness + 2) / 3;

        return len * need;

    }
};