/*
    You are given a 0-indexed m x n matrix grid consisting of positive integers. You can start at any cell in the first column of the matrix, and 
    traverse the grid in the following way: From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and 
    (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell. Return the maximum 
    number of moves that you can perform.

    Example 1:
    Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
    Output: 3
    Explanation: We can start at the cell (0, 0) and make the following moves:
    - (0, 0) -> (0, 1).
    - (0, 1) -> (1, 2).
    - (1, 2) -> (2, 3).
    It can be shown that it is the maximum number of moves that can be made.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int j=cols-2; j>=0; j--) {
            for(int i=0; i<rows; i++) {
                int n = grid[i][j];

                if(i>0 && grid[i][j] < grid[i-1][j+1])
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j+1]);
                if(grid[i][j] < grid[i][j+1])
                    dp[i][j] = max(dp[i][j], 1 + dp[i][j+1]);
                if(i<rows-1 && grid[i][j] < grid[i+1][j+1])
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
            }
        }

        int ans = 0;
        for(int i=0; i<rows; i++)
            ans = max(ans, dp[i][0]);

        return ans;
    }
};