/*
    You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in the 
    next row. That is, if you are in cell (x, y) such that x < m - 1, you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is not possible
    to move from cells in the last row. Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n) x n, where moveCost[i][j] is the cost of moving 
    from a cell with value i to a cell in column j of the next row. The cost of moving from cells in the last row of grid can be ignored. The cost of a path in grid is the sum 
    of all values of cells visited plus the sum of costs of all the moves made. Return the minimum cost of a path that starts from any cell in the first row and ends at any cell
    in the last row.

    Example 1:
    Input: grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
    Output: 17
    Explanation: The path with the minimum possible cost is the path 5 -> 0 -> 1.
    - The sum of the values of cells visited is 5 + 0 + 1 = 6. - The cost of moving from 5 to 0 is 3. - The cost of moving from 0 to 1 is 8.
    So the total cost of the path is 6 + 3 + 8 = 17.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(i == n-1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k=0; k<m; k++) {
            int val = grid[i][j];
            int cost = moveCost[val][k];
            ans = min(ans, grid[i][j] + cost + solve(i+1, k, grid, moveCost, dp));
        }

        return dp[i][j] = ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int j=0; j<m; j++)
            ans = min(ans, solve(0, j, grid, moveCost, dp));

        return ans;
    }
};