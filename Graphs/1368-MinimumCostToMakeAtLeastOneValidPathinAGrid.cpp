/*
    Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
    1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1]), 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
    3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j]), 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
    Notice that there could be some signs on the cells of the grid that point outside the grid. You will initially start at the upper left cell (0, 0). A valid path in the grid
    is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be 
    the shortest. You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only. Return the minimum cost to make the grid have at least one 
    valid path.

    Example 1:
    Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    Output: 3
    Explanation: You will start at point (0, 0).
    The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the 
    arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3) The total cost = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dir =  {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 0 -> right, 1->left, 2->down, 3->up

        int rows = grid.size();
        int cols = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        pq.push({0, 0, 0}); // {cost, row, col};
        cost[0][0] = 0;

        while(!pq.empty()) {
            int c = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            if(cost[x][y] != c)
                continue;

            for(int i=0; i<4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int newCost = c + (i == (grid[x][y] - 1) ? 0 : 1); // 0 -> right, 1->left, 2->down, 3->up therfore grid[x][y] - 1

                    if(newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }

        return cost[rows-1][cols-1];
    }
};