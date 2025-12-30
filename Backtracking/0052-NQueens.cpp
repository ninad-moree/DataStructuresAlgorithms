/*
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen 
    and an empty space, respectively.

    Example 1:
    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void addSolution(vector<vector<string>>& board, vector<vector<string>>& ans) {
        vector<string> temp;
        for(auto row : board)
            temp.push_back(accumulate(row.begin(), row.end(), string("")));
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
        // check the column
        for(int i=0;i<row;i++) {
            if(board[i][col] == "Q") 
                return false;
        }

        // check upper left diagonal
        for(int i=row, j= col; i>=0 && j>=0; i--,j--) {
            if(board[i][j] == "Q")
                return false;
        }

        // check upper right diagonal
        for(int i=row, j= col; i>=0 && j<n; i--,j++) {
            if(board[i][j] == "Q")
                return false;
        }
        
        return true;
    }

    bool isSafe2(int row, int col, vector<string>& board, int n) {
        int upperDiagonalRow = row;
        int upperDiagonalCol = col;

        while(row>=0 && col>=0) {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = upperDiagonalCol;
        row = upperDiagonalRow;

        while(col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }

        col = upperDiagonalCol;
        row = upperDiagonalRow;

        while(row<n && col>=0) {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int row, vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
        if(row == n) {
            addSolution(board, ans);
            return;
        }

        for(int col=0; col<n; col++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = "Q";
                solve(row+1, ans, board, n);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
};