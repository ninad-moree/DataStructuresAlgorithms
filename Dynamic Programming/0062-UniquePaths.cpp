/*
    There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the 
    bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
    The test cases are generated so that the answer will be less than or equal to 2 * 109.

    Example 1:
    Input: m = 3, n = 7
    Output: 28
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& dp) {
        if(row == 0 && col == 0)
            return 1;
        if(row < 0 || col < 0)
            return 0;

        if(dp[row][col] != -1)
            return dp[row][col];

        int up = solve(row-1, col, dp);
        int left = solve(row, col-1, dp);

        return dp[row][col] = (up+left);
    }

    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1)
            return 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(m-1, n-1, dp);

        return dp[m-1][n-1];
    }
};