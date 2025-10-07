/*
    You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j). It starts raining, and water gradually rises over time. At 
    time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable. You can swim from a square to another 4-directionally adjacent square
    if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid 
    during your swim. Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

    Example 1:
    Input: grid = [[0,2],[1,3]]
    Output: 3
    Explanation:
    At time 0, you are in grid location (0, 0).
    You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
    You cannot reach point (1, 1) until time 3.
    When the depth of water is 3, we can swim anywhere inside the grid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        time[0][0] = grid[0][0];

        int ans = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!pq.empty()) {
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == m - 1) 
                return t;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newTime = max(t, grid[nx][ny]);

                    if(newTime < time[nx][ny]) {
                        time[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};