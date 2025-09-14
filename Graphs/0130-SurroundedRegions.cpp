/*
    You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
    Connect: A cell is connected to adjacent cells horizontally or vertically. Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the
    board. To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

    Example 1:
    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    Explanation: In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vis[row][col] = 1;

        for(int i=0; i<4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
                dfs(nrow, ncol, vis, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int j=0; j<n; j++) {
            if(!vis[0][j] && board[0][j] == 'O') 
                dfs(0, j, vis, board);

            if(!vis[m-1][j] && board[m-1][j] == 'O')
                dfs(m-1, j, vis, board); 
        }

        for(int i=0; i<m; i++) {
            if(!vis[i][0] && board[i][0] == 'O') 
                dfs(i, 0, vis, board);

            if(!vis[i][n-1] && board[i][n-1] == 'O')
                dfs(i, n-1, vis, board); 
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};