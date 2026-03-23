/*
    You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix. Among all
    possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The 
    product of a path is the product of all integers in the grid cells visited along the path. Return the maximum non-negative product modulo 109 + 7. If the maximum product is 
    negative, return -1. Notice that the modulo is performed after getting the maximum product.

    Example 1:
    Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
    Output: -1
    Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<long long, long long> solve(int row, int col, vector<vector<int>>& grid, vector<vector<pair<long long, long long>>>& dp) {
        if(row == 0 && col == 0)
            return dp[0][0] = {grid[0][0], grid[0][0]};

        if(row < 0 || col < 0)
            return {LLONG_MIN, LLONG_MAX};

        if(dp[row][col].first != LLONG_MIN)
            return dp[row][col];

        auto up = solve(row-1, col, grid, dp);
        auto left = solve(row, col-1, grid, dp);

        vector<long long> candidates;

        if(up.first != LLONG_MIN) {
            candidates.push_back(up.first * grid[row][col]);
            candidates.push_back(up.second * grid[row][col]);
        }

        if(left.first != LLONG_MIN) {
            candidates.push_back(left.first * grid[row][col]);
            candidates.push_back(left.second * grid[row][col]);
        }

        long long maxi = *max_element(candidates.begin(), candidates.end());
        long long mini = *min_element(candidates.begin(), candidates.end());

        return dp[row][col] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m, {LLONG_MIN, LLONG_MIN}));

        auto res = solve(n-1, m-1, grid, dp);

        if(res.first < 0) 
            return -1;
        return res.first % 1000000007;
    }
};