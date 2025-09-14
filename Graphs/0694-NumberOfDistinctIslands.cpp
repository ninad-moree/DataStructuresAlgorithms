/*
    You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You
    may assume all four edges of the grid are surrounded by water. An island is considered to be the same as another if and only if one island can be 
    translated (and not rotated or reflected) to equal the other. Return the number of distinct islands.

    Example 1:
    Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& p, int row0, int col0) {
        int m = grid.size();
        int n = grid[0].size();
        
        vis[row][col] = 1;
        p.push_back({row - row0, col - col0});
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for(int i=0; i<4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                dfs(nrow, ncol, grid, vis, p, row0, col0);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> st;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> p;
                    dfs(i, j, grid, vis, p, i, j);
                    st.insert(p);
                }
            }
        }
        
        return st.size();
    }
};