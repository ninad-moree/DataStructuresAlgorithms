/*
    You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions. Return the number of strictly increasing paths in the 
    grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7. Two paths are considered different if they do 
    not have exactly the same sequence of visited cells.

    Example 1:
    Input: grid = [[1,1],[3,4]]
    Output: 8
    Explanation: The strictly increasing paths are:
    - Paths with length 1: [1], [1], [3], [4]. - Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4]. - Paths with length 3: [1 -> 3 -> 4].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= prev) 
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i+1, j, grid[i][j], grid, dp) % mod;
        int up = solve(i-1, j, grid[i][j], grid, dp) % mod;
        int left = solve(i, j-1, grid[i][j], grid, dp) % mod;
        int right = solve(i, j+1, grid[i][j], grid, dp) % mod;

        return dp[i][j] = (1 + down + up + left + right) % mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1)
                    solve(i, j, -1, grid, dp);
            }
        }

        long long ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
                ans = (ans + dp[i][j]) % mod;
        }

        return ans;
    }
};