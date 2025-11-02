/*
    You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] 
    = [rowj, colj] represent the positions of the ith guard and jth wall respectively. A guard can see every cell in the four cardinal directions (north, east, south, or west) 
    starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it. Return the number of unoccupied 
    cells that are not guarded.

    Example 1:
    Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
    Output: 7
    Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram. There are a total of 7 unguarded cells, so we return 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); 
        // 0 -> empty, 1 -> guard, 2 -> wall, 3 -> guarded
        for (auto &g : guards) 
            grid[g[0]][g[1]] = 1;

        for (auto &w : walls) 
            grid[w[0]][w[1]] = 2;

        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for (auto &g : guards) {
            for (auto &d : dirs) {
                int r = g[0] + d.first;
                int c = g[1] + d.second;
                
                while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 1 && grid[r][c] != 2) {
                    if (grid[r][c] == 0) 
                        grid[r][c] = 3; 
                    r += d.first;
                    c += d.second;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    cnt++;

        return cnt;
    }
};