/*
    You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents: A cell containing a thief if grid[r][c] = 1, An empty cell if grid[r][c] = 0
    You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves. The safeness factor of a path on 
    the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid. Return the maximum safeness factor of all paths leading to cell 
    (n - 1, n - 1). An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists. The Manhattan distance between two cells 
    (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

    Example 1:
    Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
    Output: 0
    Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // calculates the min distance of cells containing 0 from cells containing 1
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n) {
        queue<pair<int, int>> q; // positions: {x, y}
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            int s = score[x][y];
            q.pop();

            for(int i=0; i<4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >= 0 && newy < n && score[newx][newy] > 1 + s) {
                    score[newx][newy] = 1 + s;
                    q.push({newx, newy});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return 0;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score, n);

        vector<vector<int>> vis(n, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>> pq; // score[x][y], {x, y}
        pq.push({score[0][0], {0, 0}});

        while(!pq.empty()) {
            int sc = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == n-1)
                return sc;

            vis[x][y] = true;

            for(int i=0; i<4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >= 0 && newy < n && !vis[newx][newy]) {
                    int s = min(sc, score[newx][newy]);
                    pq.push({s, {newx, newy}});
                    vis[newx][newy] = true;
                }
            }
        }

        return -1;
    }
};