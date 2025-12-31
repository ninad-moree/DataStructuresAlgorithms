/*
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.
    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Example 1:
    Input: board = [["A","B","C","E"], word = "ABCCED"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;
    
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.length())
            return true;
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; 
        
        bool found = backtrack(board, word, i + 1, j, index + 1) || backtrack(board, word, i - 1, j, index + 1) || backtrack(board, word, i, j + 1, index + 1) || backtrack(board, word, i, j - 1, index + 1);
        
        board[i][j] = temp; // Revert the cell
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        
        rows = board.size();
        cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (backtrack(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};