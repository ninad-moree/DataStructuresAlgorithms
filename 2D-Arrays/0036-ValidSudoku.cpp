/*
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

    Note:
    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for(int i=0;i<9;i++) {
            if(board[row][i]==val && i!=col)
                return false;

            if(board[i][col]==val && i!=row)
                return false;
            
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val && row!=(3*(row/3)+i/3) && col!=(3*(col/3)+i%3))
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] != '.') {
                    bool ans = isSafe(i, j, board, board[i][j]);
                    if(ans == false)
                        return false;
                }
            }
        }
        return true;
    }
};