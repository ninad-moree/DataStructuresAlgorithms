/*
    Given an integer numRows, return the first numRows of Pascal's triangle.

    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if (numRows == 0) 
            return ans;

        ans.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> row(i + 1, 1); 
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }

        return ans;
    }
};
