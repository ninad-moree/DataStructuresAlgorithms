/*
    There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: 
    grid[i][j] = (i * n) + j. The snake starts at cell 0 and follows a sequence of commands. You are given an integer n representing the size of the grid and 
    an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", and "LEFT". It's guaranteed that the snake will remain within the grid 
    boundaries throughout its movement. Return the position of the final cell where the snake ends up after executing commands.

    Example 1:
    Input: n = 2, commands = ["RIGHT","DOWN"]
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0;
        int j = 0;

        for(int k=0; k<commands.size(); k++) {
            if(commands[k] == "UP")
                i--;
            else if(commands[k] == "RIGHT")
                j++;
            else if(commands[k] == "DOWN")
                i++;
            else
                j--;
        }

        int ans = (i*n) + j;
        return ans;
    }
};