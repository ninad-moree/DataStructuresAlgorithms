/*
    You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents 
    the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, 
    columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

    Example 1:
    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2
    Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!pq.empty()) {
            int eff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == m-1 && y == n-1)
                return eff;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int currEffort = max(eff, abs(heights[nx][ny] - heights[x][y]));
                    if(currEffort < effort[nx][ny]) {
                        effort[nx][ny] = currEffort;
                        pq.push({effort[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};