/*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all 
    four edges of the grid are all surrounded by water.

    Example 1:
    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') 
            return;
        
        grid[i][j] = '0';
        
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) 
            return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};