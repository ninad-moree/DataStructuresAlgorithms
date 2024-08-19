/*
    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
    A falling path starts at any element in the first row and chooses the element in the next row that 
    is either directly below or diagonally left/right. Specifically, the next element from position 
    (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

    Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        for(int i=0; i<m; i++) 
            dp[n-1][i] = matrix[n-1][i];
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<m; j++) {
                int a=INT_MAX, b=INT_MAX, c=INT_MAX;
                if(j>0)
                    a = dp[i+1][j-1];
                if(j<m-1)
                    c = dp[i+1][j+1];
                
                b = dp[i+1][j];

                dp[i][j] = matrix[i][j] + min(a, min(b, c));
            }
        }

        int ans = dp[0][0];
        for(int i=1; i<m; i++)
            ans = min(ans, dp[0][i]);

        return ans;
    }
};