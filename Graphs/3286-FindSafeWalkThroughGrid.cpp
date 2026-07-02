/*
    You are given an m x n binary matrix grid and an integer health. You start on the upper-left corner (0, 0) and would like to get to the lower-right
    corner (m - 1, n - 1). You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive. Cells
    (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1. Return true if you can reach the final cell with a health value of 1
    or more, and false otherwise.

    Example 1:
    Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
    Output: true
    Explanation:
    The final cell can be reached safely by walking along the gray cells below.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int sx, int sy, vector<vector<int>>& grid, int health, vector<vector<int>>& hea) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int sh = health - grid[0][0];
        if (sh <= 0) 
            return false;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({sh, {sx, sy}});
        hea[sx][sy] = sh;

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int h = pq.top().first;
            pq.pop();

            if(x == n-1 && y == m-1) {
                if(h >= 1)
                    return true;
                else
                    return false;
            }

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nh = (grid[nx][ny] == 1 ? h - 1 : h);

                    if(nh > hea[nx][ny] && nh > 0 ) {
                        hea[nx][ny] = nh;
                        pq.push({hea[nx][ny], {nx, ny}});
                    }
                    
                }
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> hea(n, vector<int>(m, 0));

        return bfs(0, 0, grid, health, hea);
    }
};