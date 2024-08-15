/*
    You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Example 1:
    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        int time = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while(!q.empty() && fresh>0) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();

                for(auto j : dir) {
                    int newX = x + j.first;
                    int newY = y + j.second;

                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        fresh--;
                        q.push({newX, newY});
                    }
                } 
            }

            time++;
        }

        return fresh > 0 ? -1 : time;
    }
};