/*
    You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k. You start from the top-left corner (0, 0) and want to 
    reach the bottom-right corner (m - 1, n - 1) by moving only right or down. Each cell contributes a specific score and incurs an associated cost, according to their cell 
    values: 0: adds 0 to your score and costs 0. 1: adds 1 to your score and costs 1. 2: adds 2 to your score and costs 1. ​​​​​​​
    Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.
    Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

    Example 1:
    Input: grid = [[0, 1],[2, 0]], k = 1
    Output: 2
    Explanation:​​​​​​​ The maximum possible score is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int cost, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        int cellCost = (grid[i][j] == 0) ? 0 : 1;
        cost += cellCost;

        if (cost > k) 
            return -1;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if (dp[i][j][cost] != -2)
            return dp[i][j][cost];

        int down = -1, right = -1;

        if (i + 1 < n)
            down = solve(i + 1, j, cost, k, grid, dp);
        if (j + 1 < m)
            right = solve(i, j + 1, cost, k, grid, dp);

        int best = -1;
        if (down != -1) 
            best = max(best, grid[i][j] + down);
        if (right != -1) 
            best = max(best, grid[i][j] + right);

        return dp[i][j][cost] = best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -2)));

        return solve(0, 0, 0, k, grid, dp);
    }
};