/*
    You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0). Starting from the cell (i, j), you can move to one of the 
    following cells: Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
    Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.

    Example 1:
    Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
    Output: 4
    Explanation: The image above shows one of the paths that visits exactly 4 cells.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRow(int x, int y, vector<vector<int>>& row) {
        if(row[x][y] == y)
            return y;

        return row[x][y] = findRow(x, row[x][y], row);
    }

    int findCol(int x, int y, vector<vector<int>>& col) {
        if(col[y][x] == x)
            return x;

        return col[y][x] = findCol(col[y][x], y, col);
    }

    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        vector<vector<int>> row(n, vector<int>(m+1)); // next unvisited col for every row
        vector<vector<int>> col(m, vector<int>(n+1)); // next unvisited row for every col

        for(int i=0; i<n; i++) {
            for(int j=0; j<=m; j++)
                row[i][j] = j;
        }

        for(int j=0; j<m; j++) {
            for(int i=0; i<=n; i++)
                col[j][i] = i;
        }

        q.push({0, 0});
        vis[0][0] = 1;

        row[0][0] = findRow(0, 1, row);
        col[0][0] = findCol(1, 0, col);

        int steps = 1;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == n-1 && y == m-1)
                    return steps;

                // right
                int endY = min(grid[x][y] + y, m-1);
                int k = findRow(x, y+1, row);

                while(k <= endY) {
                    if(!vis[x][k]) {
                        vis[x][k] = 1;
                        q.push({x, k});

                        row[x][k] = findRow(x, k+1, row);
                        col[k][x] = findCol(x+1, k, col);
                    }

                    k = findRow(x, k, row);
                }

                // down
                int endX = min(grid[x][y] + x, n-1);
                k = findCol(x+1, y, col);

                while(k <= endX) {
                    if(!vis[k][y]) {
                        vis[k][y] = 1;
                        q.push({k, y});

                        row[k][y] = findRow(k, y+1, row);
                        col[y][k] = findCol(k+1, y, col);
                    }

                    k = findCol(k, y, col);
                }
            }

            steps++;
        }

        return -1;
    }
};