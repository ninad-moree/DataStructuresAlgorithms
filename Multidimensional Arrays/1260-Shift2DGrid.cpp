/*
    Given a 2D grid of size m x n and an integer k. You need to shift the grid k times. In one shift operation:
    Element at grid[i][j] moves to grid[i][j + 1]. Element at grid[i][n - 1] moves to grid[i + 1][0]. Element at grid[m - 1][n - 1] moves to grid[0][0].
    Return the 2D grid after applying shift operation k times.

    Example 1:
    Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
    Output: [[9,1,2],[3,4,5],[6,7,8]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));
        int total = n * m;
        k = k % total;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // convert the grid into 1D array (before rotation)
                int oldIdx = i * m + j;

                // new idx in 1D array (after rotation)
                int newIdx = (oldIdx + k) % total;

                // changing from 1D back to 2D
                int newRow = newIdx / n;
                int newCol = newIdx % n;
                
                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};