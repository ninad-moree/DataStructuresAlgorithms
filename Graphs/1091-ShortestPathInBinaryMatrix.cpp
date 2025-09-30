/*
    Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
    A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
    All the visited cells of the path are 0. nAll the adjacent cells of the path are 8-directionally connected (i.e., they are different and they 
    share an edge or a corner). The length of a clear path is the number of visited cells of this path.

    Example 1:
    Input: grid = [[0,1],[1,0]]
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q; // {distance, {x, y}}

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;

        if(m == 1 && n == 1)
            return 1;

        q.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!q.empty()) {
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] != 1) {
                        if(dis + 1 < dist[nx][ny]) {
                            dist[nx][ny] = dis + 1;
                            q.push({dist[nx][ny], {nx, ny}});
                            
                            if(nx == m-1 && ny == n-1)
                                return dist[nx][ny] + 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};