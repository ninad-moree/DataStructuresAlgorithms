/*
    You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values: 0 represents an empty cell, 1 represents an obstacle that may be removed.
    You can move up, down, left, or right from and to an empty cell. Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the 
    lower right corner (m - 1, n - 1).

    Example 1:
    Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
    Output: 2
    Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2). It can be shown that we need to remove at least 2 obstacles, so we 
    return 2. Note that there may be other ways to remove 2 obstacles to create a path.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {cost, x, y}
        vector<vector<int>> vis(n, vector<int>(m));

        if(grid[0][0] == 1)
            pq.push({1, 0, 0});
        else
            pq.push({0, 0, 0});

        vis[0][0] = 1;

        while(!pq.empty()) {
            int x = pq.top()[1];
            int y = pq.top()[2];
            int cost = pq.top()[0];
            pq.pop();

            if(x == n-1 && y == m-1)
                return cost;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    int nextCost = grid[nx][ny] + cost;
                    pq.push({nextCost, nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};