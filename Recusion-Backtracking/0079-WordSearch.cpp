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
    bool solve(int i, int j, vector<vector<char>>& board, string word, int idx) {
        if(idx == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[idx])
            return false;

        bool found = false;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        char temp = board[i][j];
        board[i][j] = '#';

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(solve(ni, nj, board, word, idx + 1))
                return true;
        }

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(solve(i, j, board, word, 0))
                    return true;
            }
        }

        return false;
    }
};