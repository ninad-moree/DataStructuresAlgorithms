/*
    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
    A falling path starts at any element in the first row and chooses the element in the next row that 
    is either directly below or diagonally left/right. Specifically, the next element from position 
    (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

    Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
    
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int left = (j > 0) ? matrix[i - 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? matrix[i - 1][j + 1] : INT_MAX;
                int straight = matrix[i - 1][j];
                
                matrix[i][j] += min({left, right, straight});
            }
        }
        
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};