/*
    You are given a 2D integer array grid of size m x n, where grid[i][j] represents the cost of visiting cell (i, j), and an integer k. You start at the top-left cell (0, 0) 
    and want to reach the bottom-right cell (m - 1, n - 1). From each cell, you may move one step in any of the four directions: up, down, left, or right. The cost of a path is
    the sum of the values of all visited cells, including the starting and ending cells. If a cell is visited more than once, its value is included each time it is visited. 
    Return the minimum possible path cost to reach (m - 1, n - 1) using at most k turns. If no such path exists, return -1. A turn occurs when the direction changes between two
    consecutive moves. For example, moving right and then down counts as one turn, while moving right and then right does not.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dir: 0 = left, 1=right, 2=up, 3=down, 4=no prev
    int solve(int i, int j, int k, int dir, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(k < 0)
            return 1e9;

        if(i == n-1 && j == m-1)
            return grid[i][j];

        if(dp[i][j][k][dir] != -1)
            return dp[i][j][k][dir];

        int left = 1e9;
        int right = 1e9;
        int up = 1e9;
        int down = 1e9;

        // left
        if(j - 1 >= 0) {
            int newK = k;

            if(dir != 4 && dir != 0)
                newK--;

            left = grid[i][j] + solve(i, j-1, newK, 0, grid, dp);
        }

        // right
        if(j + 1 < m) {
            int newK = k;

            if(dir != 4 && dir != 1)
                newK--;

            right = grid[i][j] + solve(i, j+1, newK, 1, grid, dp);
        }

        // up
        if(i - 1 >= 0) {
            int newK = k;

            if(dir != 4 && dir != 2)
                newK--;

            up = grid[i][j] + solve(i-1, j, newK, 2, grid, dp);
        }

        // down
        if(i + 1 < n) {
            int newK = k;

            if(dir != 4 && dir != 3)
                newK--;

            down = grid[i][j] + solve(i+1, j, newK, 3, grid, dp);
        }

        return dp[i][j][k][dir] = min({left, right, down, up});
    }

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][k][direction]
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(k + 1,vector<int>(5, -1))));
        
        int ans = solve(0, 0, k, 4, grid, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};