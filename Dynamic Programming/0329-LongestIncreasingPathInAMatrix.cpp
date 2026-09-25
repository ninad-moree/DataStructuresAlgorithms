/*
    Given an m x n integers matrix, return the length of the longest increasing path in matrix. From each cell, you can either move in four directions: left, right, up, or down.
    You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

    Example 1:
    Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
    Output: 4
    Explanation: The longest increasing path is [1, 2, 6, 9].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int left = 0;
        int right = 0;
        int down = 0;
        int up = 0;

        int curr = matrix[i][j];

        if(j - 1 >= 0 && curr < matrix[i][j-1])
            left = solve(i, j-1, matrix, dp);

        if(j + 1 < m &&  curr < matrix[i][j+1])
            right = solve(i, j+1, matrix, dp);

        if(i - 1 >= 0 &&  curr < matrix[i-1][j])
            up = solve(i-1, j, matrix, dp);

        if(i + 1 < n && curr < matrix[i+1][j])
            down = solve(i+1, j, matrix, dp);

        return dp[i][j] = 1 + max({left, right, up, down});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                ans = max(ans, solve(i, j, matrix, dp));
        }

        return ans;
    }
};