/*
    You are given an m x n matrix board where each cell is part of a battleship 'X' or empty '.', return the number of the battleships on board. Battleships can only be placed 
    horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At
    least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

    Example 1:
    Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int sx, int sy, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        queue<pair<int, int>> q;

        q.push({sx, sy});
        vis[sx][sy] = 1;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 'X') {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    } 
                }
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'X' && !vis[i][j]) {
                    ans++;
                    bfs(i, j, board, vis);
                }
            }
        }

        return ans;
    }
};