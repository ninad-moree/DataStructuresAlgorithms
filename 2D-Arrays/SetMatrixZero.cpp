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
        int m = matrix.size();
        int n = matrix[0].size();
        int col = 1;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j!=0)
                        matrix[0][j] = 0;
                    else 
                        col=0;
                }
            }
        }

        for(int i=1; i<m;i++) {
            for(int j=1;j<n;j++) {
                if(matrix[0][j]==0 || matrix[i][0]==0) 
                    matrix[i][j] = 0;
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<n;j++)
                matrix[0][j]=0;
        }
        if(col==0){
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
        }
    }
};