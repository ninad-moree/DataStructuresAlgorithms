/*
    There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every 
    cell on the board exactly once. You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] 
    where grid[row][col] indicates  that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.
    Return true if grid represents a valid configuration of the knight's movements or false otherwise.

    Example 1:
    Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
    Output: true
    Explanation: The above diagram represents the grid. It can be shown that it is a valid configuration.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();

        if (grid[0][0] != 0)
            return false;

        int x=0,y=0;
        for(int i=0;i<n*n;i++) {
            if(x+2<n && y+1<n && grid[x+2][y+1]==i+1){
                x=x+2;
                y=y+1;
            }
            else if(x+1<n && y+2<n && grid[x+1][y+2]==i+1){
                x=x+1;
                y=y+2;
            }
            else if(x+2<n && y-1>=0 && grid[x+2][y-1]==i+1){
                x=x+2;
                y=y-1;
            }
            else if(x+1<n && y-2>=0 && grid[x+1][y-2]==i+1){
                x=x+1;
                y=y-2;
            }
            else if(x-2>=0 && y-1>=0 && grid[x-2][y-1]==i+1){
                x=x-2;
                y=y-1;
            }
            else if(x-2>=0 && y+1<n && grid[x-2][y+1]==i+1){
                x=x-2;
                y=y+1;
            }
            else if(x-1>=0 && y-2>=0 && grid[x-1][y-2]==i+1){
                x=x-1;
                y=y-2;
            }
            else if(x-1>=0 && y+2<n && grid[x-1][y+2]==i+1){
                x=x-1;
                y=y+2;
            }
            else if(i==(n*n-1)){
                break;
                return true;
            }
            else
                return false;
        }
        return true;
    }
};