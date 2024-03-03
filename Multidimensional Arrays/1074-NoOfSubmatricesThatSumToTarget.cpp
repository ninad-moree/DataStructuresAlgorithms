/*
    Given a matrix and a target, return the number of non-empty submatrices that sum to target.
    A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
    Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate 
    that is different: for example, if x1 != x1'.

    Example 1:
    Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
    Output: 4
    Explanation: The four 1x1 submatrices that only contain 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) 
                matrix[i][j] += matrix[i][j - 1];
        }

        int result = 0;

        for (int col1 = 0; col1 < cols; ++col1) {
            for (int col2 = col1; col2 < cols; ++col2) {
                unordered_map<int, int> prefixSumCount;
                int currentSum = 0;

                for (int row = 0; row < rows; ++row) {
                    int sum = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                    currentSum += sum;

                    if (currentSum == target) 
                        result++;

                    if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) 
                        result += prefixSumCount[currentSum - target];

                    prefixSumCount[currentSum]++;
                }
            }
        }

        return result;
    }
};