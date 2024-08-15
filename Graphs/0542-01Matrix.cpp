/*
    Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell. The distance between two adjacent cells is 1.

    Example 1:
    Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    Output: [[0,0,0],[0,1,0],[0,0,0]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, pair<int, int>>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                } else
                    vis[i][j] = 0;
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            int dist = f.first;
            int x = f.second.first;
            int y = f.second.second;
            
            for(auto d : dir) {
                int newX = x + d.first;
                int newY = y + d.second;

                if(newX>=0 && newX<n && newY>=0 && newY<m && !vis[newX][newY]) {
                    q.push({dist+1, {newX, newY}});
                    vis[newX][newY] = 1;
                    ans[newX][newY] = dist+1;
                }
            }
        }

        return ans;
    }
};