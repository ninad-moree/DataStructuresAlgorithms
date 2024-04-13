/*
    You are given a 2D integer array ranges where ranges[i] = [starti, endi] denotes that all integers between starti and endi (both inclusive) 
    are contained in the ith range.
    You are to split ranges into two (possibly empty) groups such that:
    Each range belongs to exactly one group.
    Any two overlapping ranges must belong to the same group.
    Two ranges are said to be overlapping if there exists at least one integer that is present in both ranges.
    For example, [1, 3] and [2, 5] are overlapping because 2 and 3 occur in both ranges.
    Return the total number of ways to split ranges into two groups. Since the answer may be very large, return it modulo 109 + 7.

    Example 1:
    Input: ranges = [[6,10],[5,15]]
    Output: 2
    Explanation: 
    The two ranges are overlapping, so they must be in the same group.
    Thus, there are two possible ways:
    - Put both the ranges together in group 1.
    - Put both the ranges together in group 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());

        int total = 1;
        int first = ranges[0][1];

        for(int i=1; i<ranges.size(); i++) {
            if(ranges[i][0] > first)
                total++;
            first = max(first, ranges[i][1]);
        }

        int ways = 1;
        int MOD = 1e9 + 7;

        while(total--)
            ways = (ways*2)%MOD;
        
        return ways;
    }
};