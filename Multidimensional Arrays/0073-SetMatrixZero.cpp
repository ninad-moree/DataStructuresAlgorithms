/*
    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
    You must do it in place.

    Example 1:
    Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<pair<int, int>> zeros;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) 
                    zeros.push_back({i, j});
            }
        }

        for (auto& pos : zeros) {
            int row = pos.first;
            int col = pos.second;

            for (int i = 0; i < c; i++) 
                matrix[row][i] = 0;
            
            for (int i = 0; i < r; i++) 
                matrix[i][col] = 0;
        }
    }
};