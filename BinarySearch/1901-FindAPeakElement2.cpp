/*
    A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom. Given 
    a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j]. You may
    assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell. You must write an algorithm that runs in 
    O(m log(n)) or O(n log(m)) time.

    Example 1:
    Input: mat = [[1,4],[3,2]]
    Output: [0,1]
    Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEleRow(vector<vector<int>>& mat, int colNumber) {
        int rowNo = 0;
        int maxi = mat[0][colNumber];

        for(int i=0; i<mat.size(); i++) {
            if(mat[i][colNumber] > maxi) {
                maxi = mat[i][colNumber];
                rowNo = i;
            }
        }

        return rowNo;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row, col;

        int low = 0;
        int high = mat[0].size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int rowNo = maxEleRow(mat, mid);
            int curr = mat[rowNo][mid];
            int left = -1, right = -1;

            if(mid > 0)
                left = mat[rowNo][mid-1];
            if(mid < mat[0].size() - 1)
                right = mat[rowNo][mid+1];

            if(curr > left && curr > right)
                return {rowNo, mid};
            else if(curr < left && curr > right)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};