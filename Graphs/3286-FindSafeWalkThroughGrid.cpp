/*
    You are given an m x n binary matrix grid and an integer health. You start on the upper-left corner (0, 0) and would like to get to the lower-right
    corner (m - 1, n - 1). You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive. Cells
    (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1. Return true if you can reach the final cell with a health value of 1
    or more, and false otherwise.

    Example 1:
    Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
    Output: true
    Explanation:
    The final cell can be reached safely by walking along the gray cells below.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<vector<int>> q;
        q.push({0, 0, (grid[0][0] == 1 ? health-1 : health)});

        vector<pair<int, int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> vis(rows, vector<int>(cols, -1));
        vis[0][0] = health;

        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int h = q.front()[2];
            q.pop();

            if(x == rows-1 && y == cols-1) 
                return h > 0 ? true : false;

            for(auto i : dir) {
                int newX = x + i.first;
                int newY = y + i.second;

                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    int newHealth = h - ((grid[newX][newY] == 1) ? 1 : 0);

                    if(newHealth > 0 && newHealth > vis[newX][newY]) {
                        vis[newX][newY] = newHealth;
                        q.push({newX, newY, newHealth});
                    }
                }
            }
        }

        return false;
    }
};