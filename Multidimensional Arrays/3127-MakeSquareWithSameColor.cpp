/*
    You are given a 2D matrix grid of size 3 x 3 consisting only of characters 'B' and 'W'. Character 'W' represents the white color, and character 
    'B' represents the black color. Your task is to change the color of at most one cell so that the matrix has a 2 x 2 square where all cells are 
    of the same color. Return true if it is possible to create a 2 x 2 square of the same color, otherwise, return false.

    Example 1:
    Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]
    Output: true
    Explanation:
    It can be done by changing the color of the grid[0][2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int bc = 0;
                int wc = 0;
                for(int row = i; row < i + 2; row++) {
                    for(int col = j; col < j + 2; col++) {
                        if(grid[row][col] == 'B')
                            bc++;
                        else
                            wc++;
                    }
                }
                if(bc != 2 || wc != 2)
                    return true;
            }
        }
        
        return false;
    }
};