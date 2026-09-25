/*
    You are given an n x n grid representing a field of cherries, each cell is one of three possible integers. 0 means the cell is empty, so you can pass through,
    1 means the cell contains a cherry that you can pick up and pass through, or -1 means the cell contains a thorn that blocks your way. Return the maximum number of cherries 
    you can collect by following the rules below: Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down  through valid path cells (cells with 
    value 0 or 1). After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells. When passing through a path cell containing a cherry, you 
    pick it up, and the cell becomes an empty cell 0. If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

    Example 1:
    Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
    Output: 5
    Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2). 4 cherries were picked up during this single trip, and the matrix becomes 
    [[0,1,-1],[0,0,-1],[0,0,0]]. Then, the player went left, up, up, left to return home, picking up one more cherry. The total number of cherries picked up is 5, and this is 
    the maximum possible.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int r1, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();

        //Both have taken the same number of steps --> r1 + c1 = r2 + c2
        int r2 = r1 + c1 - c2;

        if(r1 < 0 || r1 >= n || c1 < 0 || c1 >= n || r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1;

        if(dp[r1][c1][c2] != -2)
            return dp[r1][c1][c2];

        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        int cherries = grid[r1][c1];
        
        if(r1 != r2 || c1 != c2)
            cherries += grid[r2][c2]; // difft cells

        int downDown = solve(r1 + 1, c1, c2, grid, dp);

        int downRight = solve(r1 + 1, c1, c2 + 1, grid, dp);

        int rightDown = solve(r1, c1 + 1, c2, grid, dp);

        int rightRight = solve(r1, c1 + 1, c2 + 1, grid, dp);

        int best = max({downDown, downRight, rightDown, rightRight});

        if(best == -1)
            return dp[r1][c1][c2] = -1;

        return dp[r1][c1][c2] = best + cherries;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == -1 || grid[n-1][n-1] == -1)
            return -1;

        // dp[r1][c1][c2]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -2)));

        int ans = solve(0, 0, 0, grid, dp);

        return ans = max(ans, 0);
    }
};