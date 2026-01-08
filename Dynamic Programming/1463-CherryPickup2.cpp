/*
    You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell. You 
    have two robots that can collect cherries for you:
    Robot #1 is located at the top-left corner (0, 0), and Robot #2 is located at the top-right corner (0, cols - 1).
    Return the maximum number of cherries collection using both robots by following the rules below:
        From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
        When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
        When both robots stay in the same cell, only one takes the cherries.
        Both robots cannot move outside of the grid at any moment.
        Both robots should reach the bottom row in grid.
    
    Example 1:
    Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
    Output: 24
    Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
    Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12. Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
    Total of cherries: 12 + 12 = 24.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1000;
        if(row == n-1) {
            if(col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int dy[] = {-1, 0, 1};
        int maxi = -1000;

        for(int y1=0; y1<3; y1++) {
            for(int y2=0; y2<3; y2++) {
                if(col1 == col2) 
                    maxi = max(maxi, grid[row][col1] + solve(row+1, col1+dy[y1], col2+dy[y2], grid, dp));
                else
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + solve(row+1, col1+dy[y1], col2+dy[y2], grid, dp));
            }
        }

        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        solve(0, 0, m-1, grid, dp);

        return dp[0][0][m-1];
    }
};