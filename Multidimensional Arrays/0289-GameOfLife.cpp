/*
    According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by 
    the British mathematician John Horton Conway in 1970."
    The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or 
    dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the 
    following four rules (taken from the above Wikipedia article):
    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

    Example 1:
    Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        vector<vector<int>> newBoard(row, vector<int>(col));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int liveNeighbors = 0;

                for (const auto& dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;

                    if (x >= 0 && x < row && y >= 0 && y < col && board[x][y] == 1)
                        liveNeighbors++;
                }

                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) 
                        newBoard[i][j] = 0; 
                    else 
                        newBoard[i][j] = 1; 
                } else {
                    if (liveNeighbors == 3)
                        newBoard[i][j] = 1; 
                    else
                        newBoard[i][j] = 0; 
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = newBoard[i][j];
            }
        }
    }
};