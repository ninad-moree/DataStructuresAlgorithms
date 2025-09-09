/*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands. An island is surrounded 
    by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by 
    water.

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
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++) {
                int nx = x + drow[k];
                int ny = y + dcol[k];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny] == '1') {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row, vector<int>(col, 0));
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        
        return ans;
    }
};