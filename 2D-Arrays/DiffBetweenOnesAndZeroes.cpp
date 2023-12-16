/*
    You are given a 0-indexed m x n binary matrix grid.
    A 0-indexed m x n difference matrix diff is created with the following procedure:
        Let the number of ones in the ith row be onesRowi.
        Let the number of ones in the jth column be onesColj.
        Let the number of zeros in the ith row be zerosRowi.
        Let the number of zeros in the jth column be zerosColj.
        diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
    Return the difference matrix diff.

    Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
    Output: [[0,0,4],[0,0,4],[-2,-2,2]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowOnes(rows, 0);
        vector<int> colOnes(cols, 0);

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                rowOnes[i]+=grid[i][j];
                colOnes[j]+=grid[i][j];
            }
        }

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                grid[i][j] = 2*(rowOnes[i] + colOnes[j]) - rows - cols;
            }
        }
        return grid;
    }
};