/*
    Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer. Make answer equal 
    to matrix, then replace each element with the value -1 with the maximum element in its respective column.
    Return the matrix answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<cols;i++) {
            int colMax = INT_MIN;
            for(int j=0;j<rows;j++) {
                if(matrix[j][i] > colMax)
                    colMax = matrix[j][i];
            }
            for(int j=0;j<rows;j++) {
                if(matrix[j][i] == -1)
                    matrix[j][i] = colMax;
            }
        }

        return matrix;
    }
};