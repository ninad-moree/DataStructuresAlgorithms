/*
    A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
    Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
    Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

    Example 1:
    Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int ans = 0;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i+2>=r || j+2>=c)
                    continue;
                
                int diag1Sum = 0, diag2Sum = 0, rowSum = -1, colSum = -1;
                set<int>s;

                for(int row=0; row<3; row++) {
                    int curRow = 0, curCol = 0;
                    for(int col=0; col<3; col++) {
                        if(grid[row+i][col+j] > 9 || grid[row+i][col+j] <= 0)
                            continue;
                        
                        s.insert(grid[row+i][col+j]);

                        if(row == col)
                            diag1Sum += grid[row+i][col+j];
                        if(row+col == 2)
                            diag2Sum += grid[row+i][col+j];

                        curRow += grid[row+i][col+j];
                        curCol += grid[col+i][row+j];
                    }

                    if((rowSum != -1 && curRow != rowSum) || (colSum != -1 && curCol != colSum))
                        break;
                    else {
                        rowSum = curRow;
                        colSum = curCol;
                    }
                        
                }

                if(s.size() == 9 && diag1Sum == diag2Sum && diag1Sum == rowSum && rowSum == colSum)
                    ans++;
            }
        }

        return ans;
    }
};
