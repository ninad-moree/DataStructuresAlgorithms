/*
    Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in 
    that row. In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
    Return an array containing the index of the row, and the number of ones in it.

    Example 1:
    Input: mat = [[0,1],[1,0]]
    Output: [0,1]
    Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the 
    answer is [0,1]. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rowNo = 0;
        int one = 0;

        for(int i=0; i<mat.size(); i++) {
            int curr = 0;
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 1)
                    curr++;
            }
            if(curr > one) {
                rowNo = i;
                one = curr;
            }
        }

        return {rowNo, one};
    }
};