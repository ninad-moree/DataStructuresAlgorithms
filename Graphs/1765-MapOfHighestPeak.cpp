/*
    You are given an integer matrix isWater of size m x n that represents a map of land and water cells. If isWater[i][j] == 0, cell (i, j) is a land cell. If isWater[i][j] == 
    1, cell (i, j) is a water cell. You must assign each cell a height in a way that follows these rules: The height of each cell must be non-negative. If the cell is a water 
    cell, its height must be 0. Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the  former is directly north,
    east, south, or west of the latter (i.e., their sides are touching). Find an assignment of heights such that the maximum height in the matrix is maximized. Return an 
    integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

    Example 1:
    Input: isWater = [[0,1],[0,0]]
    Output: [[1,0],[2,1]]
    Explanation: The image shows the assigned heights of each cell. The blue cell is the water cell, and the green cells are the land cells.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> ans(n, vector<int>(m));

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int dist = 1;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                        ans[nx][ny] = dist;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            dist++;
        }

        return ans;
    }
};