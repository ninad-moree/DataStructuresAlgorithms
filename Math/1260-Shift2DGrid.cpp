/*
    Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
    In one shift operation:
    Element at grid[i][j] moves to grid[i][j + 1].
    Element at grid[i][n - 1] moves to grid[i + 1][0].
    Element at grid[m - 1][n - 1] moves to grid[0][0].
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
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int newIndex = (j + k) % cols;
                int newRow = (j + k) / cols + i;

                if (newIndex < 0) {
                    newIndex += cols;
                    newRow--;
                }

                newRow = newRow % rows; 
                ans[newRow][newIndex] = grid[i][j];
            }
        }

        return ans;
    }
};