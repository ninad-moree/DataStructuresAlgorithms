/*
    You are given a 0-indexed integer matrix grid and an integer k.
    Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

    Example 1:
    Input: grid = [[7,6,3],[6,6,1]], k = 18
    Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i>0)
                    grid[i][j] += grid[i-1][j];
                if(j>0)
                    grid[i][j] += grid[i][j-1];
                if(i>0 && j>0)
                    grid[i][j] -= grid[i-1][j-1];
                
                if(grid[i][j] <= k)
                    ans++;
            }
        }

        return ans;
    }
};