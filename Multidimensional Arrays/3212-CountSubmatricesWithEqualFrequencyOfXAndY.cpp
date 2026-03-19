/*
    Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
    grid[0][0], an equal frequency of 'X' and 'Y' and at least one 'X'.
    

    Example 1:
    Input: grid = [["X","Y","."],["Y",".","."]]
    Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> mat(n, vector<int>(m, 0));
        vector<vector<int>> countX(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'X') {
                    mat[i][j] = 1;
                    countX[i][j] = 1;
                }
                else if(grid[i][j] == 'Y')
                    mat[i][j] = -1;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i>0) {
                    mat[i][j] += mat[i-1][j];
                    countX[i][j] += countX[i-1][j];
                }
                if(j>0) {
                    mat[i][j] += mat[i][j-1];
                    countX[i][j] += countX[i][j-1];
                }
                if(i>0 && j>0) {
                    mat[i][j] -= mat[i-1][j-1];
                    countX[i][j] -= countX[i-1][j-1];
                }
                if(mat[i][j] == 0 && countX[i][j] > 0)
                    ans++;
            }
        }

        return ans;
    }
};