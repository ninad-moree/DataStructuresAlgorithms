/*
    You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land 
    cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Return the number of land cells in grid for which we
    cannot walk off the boundary of the grid in any number of moves.

    Example 1:
    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3
    Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) 
                    ans++;
            }
        }

        return ans;
    }
};