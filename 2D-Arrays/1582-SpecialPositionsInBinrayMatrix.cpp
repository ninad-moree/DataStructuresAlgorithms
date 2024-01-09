/*
    Given an m x n binary matrix mat, return the number of special positions in mat.
    A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 
    (rows and columns are 0-indexed).

    Example 1:
    Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
    Output: 1
    Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rowCount = mat.size();
        int colCount = mat[0].size();
        int specialCount = 0;

        vector<int> rowSum(rowCount, 0);
        vector<int> colSum(colCount, 0);

        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    specialCount++;
                }
            }
        }

        return specialCount;
    }
};