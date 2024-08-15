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
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;

        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()) {
            auto f = pq.top();
            int ef = f.first;
            int x = f.second.first;
            int y = f.second.second;
            pq.pop();

            if(x == n-1 && y == m-1)
                return ef;

            for(auto d : dir) {
                int newX = x + d.first;
                int newY = y + d.second;

                if(newX>=0 && newX<n && newY>=0 && newY<m) {
                    int currEff = max(abs(heights[newX][newY] - heights[x][y]), ef);
                    if(currEff < effort[newX][newY]) {
                        effort[newX][newY] = currEff;
                        pq.push({currEff, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};