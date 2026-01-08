/*
    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix. A falling path starts at any element in the 
    first row and chooses the element in the next row that  is either directly below or diagonally left/right. Specifically, the next element from 
    position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

    Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(col < 0 || col >= m)
            return 1e9;
        if(row == 0)
            return matrix[row][col];

        if(dp[row][col] != INT_MAX)
            return dp[row][col];

        int diagLeft = matrix[row][col] + solve(row-1, col-1, matrix, dp);
        int up = matrix[row][col] + solve(row-1, col, matrix, dp);
        int diagRight = matrix[row][col] + solve(row-1, col+1, matrix, dp);

        return dp[row][col] = min(diagLeft, min(diagRight, up));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(n == 1)
            return matrix[0][0];

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for(int j=0; j<m; j++)
            solve(n-1, j, matrix, dp);

        int ans = 1e9;
        for(int j=0; j<m; j++)
            ans = min(ans, dp[n-1][j]);

        return ans;
    }
};