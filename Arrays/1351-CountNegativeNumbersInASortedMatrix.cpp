/*
    Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

    Example 1:
    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int r = 0;
        int c = m-1;
        int ans = 0;

        while(r < n && c >= 0) {
            if(grid[r][c] < 0) {
                ans += (n - r);
                c--;
            } else
                r++;
        }

        return ans;
    }
};