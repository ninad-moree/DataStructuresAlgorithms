/*
    You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
    1 which means a street connecting the left cell and the right cell. 2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell. 4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell. 6 which means a street connecting the right cell and the upper cell.
    You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the 
    bottom-right cell (m - 1, n - 1). The path should only follow the streets. Notice that you are not allowed to change any street. Return true if there is a valid path in the 
    grid or false otherwise.

    Example 1:
    Input: grid = [[2,4,3],[6,5,2]]
    Output: true
    Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, vector<pair<int,int>>> mp;
        mp[1] = {{0, -1}, {0, 1}};   // left, right
        mp[2] = {{-1, 0}, {1, 0}};   // up, down
        mp[3] = {{0, -1}, {1, 0}};   // left, down
        mp[4] = {{0, 1},  {1, 0}};   // right, down
        mp[5] = {{0, -1}, {-1, 0}};  // left, up
        mp[6] = {{0, 1},  {-1, 0}};  // right, up

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> vis(n, vector<int>(m));
        vis[0][0] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n-1 && y == m-1)
                return true;

            for (auto i : mp[grid[x][y]]) {
                int dx = i.first;
                int dy = i.second;
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny])
                    continue;

                bool connected = false;
                for (auto j : mp[grid[nx][ny]]) {
                    int ndx = j.first;
                    int ndy = j.second;
                    if (ndx == -dx && ndy == -dy) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};