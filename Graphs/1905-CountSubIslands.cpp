/*
    You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group 
    of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells. An island in grid2 is 
    considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
    Return the number of islands in grid2 that are considered sub-islands.

    Example 1:
    Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
    Output: 3
    Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
    The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool island = false;

    void dfs(int x, int y, vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int n = g2.size();
        int m = g2[0].size();

        if(g1[x][y] != g2[x][y])
            island = false;
        
        g2[x][y] = 0;
        g1[x][y] = 0;

        vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto d : dir) {
            int newX = x + d.first;
            int newY = y + d.second;

            if(newX>=0 && newX<n && newY>=0 && newY<m && g2[newX][newY]==1)
                dfs(newX, newY, g1, g2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid2[i][j] == 1) {
                    island = true;
                    dfs(i, j, grid1, grid2);
                    if(island)
                        ans++;
                }
            }
        }

        return ans;
    }
};