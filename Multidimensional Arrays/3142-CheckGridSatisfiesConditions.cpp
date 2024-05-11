/*
    You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:
    Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
    Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
    Return true if all the cells satisfy these conditions, otherwise, return false.

    Example 1:
    Input: grid = [[1,0,2],[1,0,2]]
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < m; j++) { 
                if(n!=i+1 && grid[i][j] != grid[i+1][j])
                    return false;
                if(m!=j+1 && grid[i][j] == grid[i][j+1])
                    return false;
            }
        }
        
        return true;
    } 
};