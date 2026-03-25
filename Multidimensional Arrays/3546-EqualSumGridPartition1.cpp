/*
    You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
    Each of the two resulting sections formed by the cut is non-empty. The sum of the elements in both sections is equal. Return true if such a partition exists; otherwise return
    false.

    Example 1:
    Input: grid = [[1,4],[2,3]]
    Output: true
    Explanation: A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                total += grid[i][j];
        }

        if(total % 2 != 0) 
            return false;

        long long curr = 0;
        for(int i = 0; i < m - 1; i++) { 
            for(int j = 0; j < n; j++) 
                curr += grid[i][j];
            
            if(curr == total - curr) 
                return true;
        }

        curr = 0;
        for(int j = 0; j < n - 1; j++) { 
            for(int i = 0; i < m; i++) 
                curr += grid[i][j];
            
            if(curr == total - curr) 
                return true;
        }

        return false;
    }
};