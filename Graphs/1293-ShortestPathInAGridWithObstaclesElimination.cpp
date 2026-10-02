/*
    You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
    Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If 
    it is not possible to find such walk return -1.

    Example 1:
    Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
    Output: 6
    Explanation:  The shortest path without eliminating any obstacle is 10. The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) 
    -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<vector<int>> q; // {x, y, k remaining}
        vector<vector<int>> vis(n, vector<int>(m, -1));

        q.push({0, 0, k});
        int dis = 0;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int x = q.front()[0];
                int y = q.front()[1];
                int K = q.front()[2];
                q.pop();

                if(x == n-1 && y == m-1)
                    return dis;

                if(grid[x][y] == 1) {
                    if(K > 0)
                        K--;
                    else
                        continue;
                }

                if(vis[x][y] != -1 && vis[x][y] >= K)
                    continue;

                vis[x][y] = K;

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m) 
                        q.push({nx, ny, K});
                    
                }
            }

            dis++;
        }

        return -1;
    }
};