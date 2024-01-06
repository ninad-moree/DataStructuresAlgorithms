/*
    Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

    Example 1:
    Input: n = 3
    Output: [[1,2,3],[8,9,4],[7,6,5]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int cnt = 1;
        int total = n * n;

        int s_row = 0;
        int e_row = n - 1;
        int s_col = 0;
        int e_col = n - 1;

        while (cnt <= total) {
            for (int i = s_col; i <= e_col && cnt <= total; i++)
                matrix[s_row][i] = cnt++;
            s_row++;

            for (int i = s_row; i <= e_row && cnt <= total; i++)
                matrix[i][e_col] = cnt++;
            e_col--;

            for (int i = e_col; i >= s_col && cnt <= total; i--)
                matrix[e_row][i] = cnt++;
            e_row--;

            for (int i = e_row; i >= s_row && cnt <= total; i--)
                matrix[i][s_col] = cnt++;
            s_col++;
        }

        return matrix;
    }
};