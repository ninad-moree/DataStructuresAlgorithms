/*
    You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following: A stone '#' A stationary obstacle '*'
    Empty '.' The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or 
    the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions. It is 
    guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box. Return an n x m matrix representing the box after the rotation described
    above.

    Example 1:
    Input: boxGrid = [["#",".","#"]]
    Output: [["."], ["#"], ["#"]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> grid(m, vector<char>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = boxGrid[n - 1 - j][i];

        int rows = grid.size();    
        int cols = grid[0].size(); 

        for (int j = 0; j < cols; j++) {
            int emptySlot = rows - 1;
            for (int i = rows - 1; i >= 0; i--) {
                if (grid[i][j] == '*') 
                    emptySlot = i - 1;
                else if (grid[i][j] == '#') {
                    grid[i][j] = '.';
                    grid[emptySlot][j] = '#';
                    emptySlot--;
                }
            }
        }

        return grid;
    }
}; 