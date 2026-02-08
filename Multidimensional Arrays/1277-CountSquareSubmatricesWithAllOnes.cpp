/*
    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example 1:
    Input: matrix =
    [
        [0,1,1,1],
        [1,1,1,1],
        [0,1,1,1]
    ]
    Output: 15
    Explanation:  There are 10 squares of side 1. There are 4 squares of side 2. There is  1 square of side 3. Total number of squares = 10 + 4 + 1 = 15.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        for(int i=0; i<n; i++)
            dp[i][0] = matrix[i][0];

        for(int j=0; j<m; j++)
            dp[0][j] = matrix[0][j];

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j] == 1)
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
                ans += dp[i][j];
        }

        return ans;
    }
};