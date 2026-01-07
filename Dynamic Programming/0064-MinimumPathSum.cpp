/*
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its
    path. You can only move either down or right at any point in time.

    Example 1:
    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        if(row == 0 && col == 0)
            return dp[0][0] = grid[0][0]; 
        if(row < 0 || col < 0)
            return 1000000;

        if(dp[row][col] != -1)
            return dp[row][col];

        int up = grid[row][col] + solve(grid, dp, row-1, col);
        int left = grid[row][col] + solve(grid, dp, row, col-1);

        return dp[row][col] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        solve(grid, dp, m-1, n-1);

        return dp[m-1][n-1];
    }
};