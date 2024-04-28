/*
    You are given a 2D boolean matrix grid.
    Return an integer that is the number of right triangles that can be made with the 3 elements of grid such that all of them have a value of 1.

    Example 1:
    0	1	0      0	1	0
    0	1	1      0	1	1
    0	1	0      0	1	0
    Input: grid = [[0,1,0],[0,1,1],[0,1,0]]
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        long long count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) 
                    count += (long long)(rowCount[i] - 1) * (colCount[j] - 1);
            }
        }

        return count;
    }
};