/*
    You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order. Return the area of the largest submatrix within 
    matrix where every element of the submatrix is 1 after reordering the columns optimally.

    Example 1:
    Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
    Output: 4
    Explanation: You can rearrange the columns as shown above. The largest submatrix of 1s, in bold, has an area of 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        for (int col = 0; col < cols; ++col) {
            for (int row = 1; row < rows; ++row) {
                if (matrix[row][col] == 1) 
                    matrix[row][col] += matrix[row - 1][col];
            }
        }

        for (auto& row : matrix) 
            sort(row.begin(), row.end(), greater<int>());

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) 
                result = max(result, matrix[row][col] * (col + 1));
        }

        return result;
    }
};