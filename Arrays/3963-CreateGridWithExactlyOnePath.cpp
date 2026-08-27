/*
    You are given two integers m and n, representing the number of rows and columns of a grid. Construct any m x n grid consisting only of the characters '.' and '#', where:
    '.' represents a free cell. '#' represents an obstacle cell. A valid path is a sequence of free cells that: Starts at the top-left cell (0, 0). Ends at the bottom-right 
    cell (m - 1, n - 1). Moves only: Right, from (i, j) to (i, j + 1), or Down, from (i, j) to (i + 1, j).
    Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.

    Example 1:
    Input: m = 2, n = 3
    Output: ["..#","#.."]
    Explanation: The only valid path is: (0,0) → (0,1) → (1,1) → (1,2)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string res = "";
        for(int i=0; i<n; i++)
            res += '#';
        vector<string> ans(m, res);

        for(int i=0; i<m; i++) 
            ans[i][0] = '.';
        
        for(int j=0; j<n; j++) 
            ans[m-1][j] = '.';
        
        return ans;
    }
};