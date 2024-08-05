/*
    You are given an m x n binary matrix grid. A row or column is considered palindromic if its values read the same forward and backward.
    You can flip any number of cells in grid from 0 to 1, or from 1 to 0. Return the minimum number of cells that need to be flipped to make either 
    all rows palindromic or all columns palindromic.

    Example 1:
    Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
    Output: 2
    Explanation:
    Flipping the highlighted cells makes all the rows palindromic.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int col = 0;
        int row = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(auto i : grid) {
            int l = 0;
            int r = m-1;

            while(l<r) {
                if(i[l] != i[r]) 
                    row++;
                l++;
                r--;
            }
        }

        for(int i=0; i<m; i++) {
            int l = 0;
            int r = n-1;

            while(l<r) {
                if(grid[l][i] != grid[r][i])
                    col++;
                l++;
                r--;
            }
        }

        return min(col, row);
    }
};