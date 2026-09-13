/*
    You are given an integer n, a 2D integer array grid of size n x n, and two integer arrays rowShift and colShift, each of length n, where: rowShift[i] represents the number 
    of positions to cyclically shift the ith row of grid to the left. colShift[j] represents the number of positions to cyclically shift the jth column of grid upward.
    First, cyclically shift each row according to rowShift, then cyclically shift each column of the resulting grid according to colShift. Return the resulting grid after 
    performing all the shifts. A cyclic left shift of a row by k positions moves the element at column j to column (j - k + n) % n. All other rows remain unchanged.
    A cyclic upward shift of a column by k positions moves the element at row i to row (i - k + n) % n. All other columns remain unchanged.

    Example 1:
    Input: n = 2, grid = [[1,2],[3,4]], rowShift = [1,0], colShift = [0,1]
    Output: [[2,4],[3,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> temp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                temp[i][j] = grid[i][(j + rowShift[i]) % n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                grid[j][i] = temp[(j + colShift[i]) % n][i];
        }

        return grid;
    }
};