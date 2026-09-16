/*
    Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each 
    segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed
    to share endpoints. Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

    Example 1:
    Input: n = 4, k = 2
    Output: 5
    Explanation: The two line segments are shown in red and blue. The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, 
    {(0,1),(1,2)}.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int idx, int n, int k, int open, vector<vector<vector<int>>>& dp) {
        if(idx >= n) 
            return 0;
        if(k == 0)
            return 1;

        if(dp[idx][k][open] != -1)
            return dp[idx][k][open];

        long long ans = 0;

        if (open) {
            // skip the current point
            ans += solve(idx, n, k, 0, dp);

            // take the point and close it
            ans += solve(idx+1, n, k, 1, dp);
        } else {
            // close the segment
            ans += solve(idx+1, n, k-1, 1, dp);

            // take and extend segment
            ans += solve(idx+1, n, k, 0, dp);
        }

        return dp[idx][k][open] = ans % MOD;
    }

    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));

        return solve(0, n, k, 1, dp);
    }
};