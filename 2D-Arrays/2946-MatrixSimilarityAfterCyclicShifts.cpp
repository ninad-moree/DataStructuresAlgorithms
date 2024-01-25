/*
    You are given a 0-indexed m x n integer matrix mat and an integer k. You have to cyclically right 
    shift odd indexed rows k times and cyclically left shift even indexed rows k times.
    Return true if the initial and final matrix are exactly the same and false otherwise.

    Example 1:
    Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEqual(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int n = mat1[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat1[i][j] != mat2[i][j])
                    return false;
            }
        }
        return true;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> initialMatrix = mat;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {  
                for (int l = 0; l < k; l++) {
                    int x = mat[i][0];
                    for (int j = 0; j < m - 1; j++) 
                        mat[i][j] = mat[i][j + 1];
                    mat[i][m - 1] = x;
                }
            } 
            else {  
                for (int l = 0; l < k; l++) {
                    int x = mat[i][m - 1];
                    for (int j = m - 1; j > 0; j--) 
                        mat[i][j] = mat[i][j - 1];
                    mat[i][0] = x;
                }
            }
        }

        return isEqual(initialMatrix, mat);
    }
};