/*
    You are given an m x n matrix grid consisting of positive integers. You can move from a cell in the matrix to any other cell that is either to 
    the bottom or to the right (not necessarily adjacent). The score of a move from a cell with the value c1 to a cell with the value c2 is c2 - c1.
    You can start at any cell, and you have to make at least one move. Return the maximum total score you can achieve.

    Example 1:
    Input: grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
    Output: 9
    Explanation: We start at the cell (0, 1), and we perform the following moves:
    - Move from the cell (0, 1) to (2, 1) with a score of 7 - 5 = 2.
    - Move from the cell (2, 1) to (2, 2) with a score of 14 - 7 = 7.
    The total score is 2 + 7 = 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> maxi(n, vector<int>(m, INT_MIN));
        maxi[n-1][m-1] = grid[n-1][m-1];
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(i < n-1)
                    maxi[i][j] = max(maxi[i][j], maxi[i+1][j]);
                if(j < m-1)
                    maxi[i][j] = max(maxi[i][j], maxi[i][j+1]);
                maxi[i][j] = max(maxi[i][j], grid[i][j]);
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i < n-1)
                    ans = max(ans, maxi[i+1][j] - grid[i][j]);
                if(j < m-1)
                    ans = max(ans, maxi[i][j+1] - grid[i][j]);
            }
        }
        
        return ans;
    }
};