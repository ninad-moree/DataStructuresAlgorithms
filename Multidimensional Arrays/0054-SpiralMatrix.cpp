/*
    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int cnt = 0;
        int total = row*col;

        int s_row = 0;
        int e_row = row-1;
        int s_col = 0;
        int e_col = col-1;

        while(cnt<total) {
            for(int i=s_col ; cnt<total && i<=e_col ; i++) {
                ans.push_back(matrix[s_row][i]);
                cnt++;
            }
            s_row++;

            for(int i=s_row ; cnt<total && i<=e_row ; i++) {
                ans.push_back(matrix[i][e_col]);
                cnt++;
            }
            e_col--;

            for(int i=e_col ; i>=s_col && cnt<total ; i--) {
                ans.push_back(matrix[e_row][i]);
                cnt++;
            }
            e_row--;

            for(int i=e_row ; i>=s_row && cnt<total ; i--) {
                ans.push_back(matrix[i][s_col]);
                cnt++;
            }
            s_col++;
        }

        return ans;
    }
};