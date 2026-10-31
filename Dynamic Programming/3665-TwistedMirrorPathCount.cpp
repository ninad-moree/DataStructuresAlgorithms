/*
    Given an m x n binary grid grid where: grid[i][j] == 0 represents an empty cell, and grid[i][j] == 1 represents a mirror. A robot starts at the top-left corner of the grid 
    (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). It can move only right or down. If the robot attempts to move into a mirror cell, it is reflected before 
    entering that cell: If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror. If it tries to move down into a mirror, it
    is turned right and moved into the cell directly to the right of the mirror. If this reflection would cause the robot to move outside the grid boundaries, the path is 
    considered invalid and should not be counted. Return the number of unique valid paths from (0, 0) to (m - 1, n - 1). Since the answer may be very large, return it modulo 
    109 + 7. Note: If a reflection moves the robot into a mirror cell, the robot is immediately reflected again based on the direction it used to enter that mirror: if it 
    entered while moving right, it will be turned down; if it entered while moving down, it will be turned right. This process will continue until either the last cell is 
    reached, the robot moves out of bounds or the robot moves to a non-mirror cell.

    Example 1:
    Input: grid = [[0,1,0],[0,0,1],[1,0,0]]
    Output: 5
    Explanation: Paths Are:
    (0, 0) → (0, 1) [M] → (1, 1) → (1, 2) [M] → (2, 2); (0, 0) → (0, 1) [M] → (1, 1) → (2, 1) → (2, 2); (0, 0) → (1, 0) → (1, 1) → (1, 2) [M] → (2, 2)
    (0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2); (0, 0) → (1, 0) → (2, 0) [M] → (2, 1) → (2, 2)
    [M] indicates the robot attempted to enter a mirror cell and instead reflected.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(x < 0 || x >= n || y < 0 || y >= m)
            return 0;

        if(x == n - 1 && y == m - 1)
            return 1;

        if(dp[x][y] != -1)
            return dp[x][y];

        // down
        int nx = x + 1, ny = y;
        bool movingDown = true;   

        while(nx < n && ny < m && grid[nx][ny] == 1 && !(nx == n - 1 && ny == m - 1)) {
            if(movingDown) {      // entered mirror going down -> turn right
                ny++;
                movingDown = false;
            } else {              // entered mirror going right -> turn down
                nx++;
                movingDown = true;
            }
        }

        long long down = solve(nx, ny, grid, dp);

        // right
        nx = x;
        ny = y + 1;
        movingDown = false;

        while(nx < n && ny < m && grid[nx][ny] == 1 && !(nx == n - 1 && ny == m - 1)) {
            if(movingDown) {
                ny++;
                movingDown = false;
            } else {
                nx++;
                movingDown = true;
            }
        }

        long long right = solve(nx, ny, grid, dp);

        return dp[x][y] = (down + right) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, grid, dp);
    }
};