/*
    Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

    Example 1:
    Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
    Output: true
    Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int i=0; i<4; i++) {
            for(int row=0; row<n/2; row++) {
                for(int col=0; col<(n+1)/2; col++) {
                    int temp = mat[row][col];
                    mat[row][col] = mat[n - 1 - col][row];
                    mat[n - 1 - col][row] = mat[n - 1 - row][n - 1 - col];
                    mat[n - 1 - row][n - 1 - col] = mat[col][n - 1 - row];
                    mat[col][n - 1 - row] = temp;
                }
            }

            if(mat == target)
                return true;
        }

        return false;
    }
};