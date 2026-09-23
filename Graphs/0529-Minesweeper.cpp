/*
    Let's play the minesweeper game (Wikipedia, online game)! You are given an m x n char matrix board representing the game board where: 'M' represents an unrevealed mine, 
    'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
    digit ('1' to '8') represents how many mines are adjacent to this revealed square, and 'X' represents a revealed mine.
    You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').
    Return the board after revealing this position according to the following rules:
    If a mine 'M' is revealed, then the game is over. You should change it to 'X'. If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank
    'B' and all of its adjacent unrevealed squares should be revealed recursively. If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit
    ('1' to '8') representing the number of adjacent mines. Return the board when no more squares will be revealed.
    
    Example 1:
    Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
    Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();

        int sx = click[0];
        int sy = click[1];

        if(board[sx][sy] == 'M') {
            board[sx][sy] = 'X';
            return board;
        }

        queue<pair<int, int>> q;
        q.push({sx, sy});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sx][sy] = 1;

        int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
        int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            vector<pair<int, int>> neigh;
            int cntBomb = 0;

            for(int i=0; i<8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    // neighbor is bomb
                    if(board[nx][ny] == 'M')
                        cntBomb++;
                    else if(board[nx][ny] == 'E')
                        neigh.push_back({nx, ny});
                }
            }

            if(cntBomb == 0) {
                board[x][y] = 'B';

                for(auto i : neigh) {
                    int nx = i.first;
                    int ny = i.second;

                    if(!vis[nx][ny]) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            } else 
                board[x][y] = cntBomb + '0';
        }

        return board;
    }
};