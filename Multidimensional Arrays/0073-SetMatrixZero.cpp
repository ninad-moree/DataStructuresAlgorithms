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
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows(n, 0);
        vector<int> cols(m, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(rows[i] == 1)
                    matrix[i][j] = 0;
                
                if(cols[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};