/*
    You are given a 2D integer array grid of size m * n. You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1). At each step, you may 
    move either right or down. The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells. Return the 
    minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

    Example 1:
    Input: grid = [[1,2],[3,4]]
    Output: 6
    Explanation: There are two valid paths: (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7, (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
    The minimum XOR value among all valid paths is 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, int xr, vector<vector<int>>& grid, vector<vector<vector<bool>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        xr ^= grid[i][j];

        if(dp[i][j][xr])
            return;

        dp[i][j][xr] = true;

        if(i+1 < n)
            solve(i+1, j, xr, grid, dp);
        
        if(j+1 < m)
            solve(i, j+1, xr, grid, dp);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Can we reach cell (i, j) with a path XOR equal to x, stores true and false
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(1024, false)));

        solve(0, 0, 0, grid, dp);

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][m - 1][x])
                return x;
        }

        return -1;
    }
};