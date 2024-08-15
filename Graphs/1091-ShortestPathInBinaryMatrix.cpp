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
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        
        int ans = 1;

        while(!q.empty()) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();
                
                int x = f.first;
                int y = f.second;

                if(x == n-1 && y == m-1)
                    return ans;

                for(auto d : dir) {
                    int newX = x + d.first;
                    int newY = y + d.second;

                    if(newX>=0 && newX<n && newY>=0 && newY<m && !vis[newX][newY] && grid[newX][newY] == 0) {
                        vis[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};