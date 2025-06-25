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

        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;

        while(left <= right && top <= bottom) {
            for(int i=left; i<=right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            for(int i=top; i<=bottom; i++) 
                ans.push_back(matrix[i][right]);
            right--;

            if(top <= bottom) {
                for(int i=right; i>=left; i--) 
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            if(left <= right) {
                for(int i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};