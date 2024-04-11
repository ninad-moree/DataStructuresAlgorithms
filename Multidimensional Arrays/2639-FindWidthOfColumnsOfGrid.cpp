/*
    You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.
    For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
    Return an integer array ans of size n where ans[i] is the width of the ith column.
    The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.

    Example 1:
    Input: grid = [[1],[22],[333]]
    Output: [3]
    Explanation: In the 0th column, 333 is of length 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;

        for(int i = 0; i < grid[0].size(); i++) {
            int maxi = 0;
            for(int j = 0; j < grid.size(); j++) {
                int num = grid[j][i];
                int n1 = abs(num); 
                int curr = 0;

                if(num < 0)
                    curr++;
                
                if(n1 ==0) 
                    curr++;

                while(n1 > 0) {
                    n1 = n1 / 10;
                    curr++;
                }

                maxi = max(curr, maxi);
            }
            
            ans.push_back(maxi);
        }

        return ans;
    }
};