/*
    Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        for(int i=0; i<n; i++)
            dp[i][0] = matrix[i][0] - '0';

        for(int j=0; j<m; j++)
            dp[0][j] = matrix[0][j] - '0';

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }

        int maxi = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
                maxi = max(maxi, dp[i][j]);
        }

        return maxi * maxi;
    }
};