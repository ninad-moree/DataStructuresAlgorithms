/*
    Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid. A cycle is a path of length 4 or more in 
    the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right),
    if it has the same value of the current cell. Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is 
    invalid because from (1, 2) we visited (1, 1) which was the last visited cell. Return true if any cycle of the same value exists in grid, otherwise, return false.

    Example 1:
    Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int sx, int sy, int px, int py, vector<vector<char>>& grid,vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q; // {x, y, px, py} --> x, y, parent x , parent y
        q.push({sx, sy, px, py}); 
        vis[sx][sy] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int parx = q.front()[2];
            int pary = q.front()[3];
            q.pop();

            if(x == sx && y == sy && parx != px && pary != py)
                return true;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == grid[x][y] && (nx != parx || ny != pary)) {
                    q.push({nx, ny, x, y});
                    vis[nx][ny] = 1;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && bfs(i, j, -1, -1, grid, vis))
                    return true;
            }
        }

        return false;
    }
};