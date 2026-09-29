/*
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true: It is (). It can be written as AB (A 
    concatenated with B), where A and B are valid parentheses strings. It can be written as (A), where A is a valid parentheses string. You are given an m x n matrix of 
    parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions: The path starts from the upper left cell (0, 0).
    The path ends at the bottom-right cell (m - 1, n - 1). The path only ever moves down or right. The resulting parentheses string formed by the path is valid.
    Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

    Example 1:
    Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
    Output: true
    Explanation: The above diagram shows two possible paths that form valid parentheses strings. The first path shown results in the valid parentheses string "()(())".
    The second path shown results in the valid parentheses string "((()))". Note that there may be other valid parentheses string paths.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        // A valid parentheses string must have even length
        if ((n + m - 1) % 2 != 0)
            return false;

        int len = n + m - 1;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(len + 1, false)));

        if (grid[0][0] == '(')
            dp[0][0][1] = true;
        else
            return false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 && j == 0)
                    continue;

                for(int balance=0; balance<=len; balance++) {
                    if(grid[i][j] == '(') {
                        // down
                        if(i > 0 && balance > 0 && dp[i-1][j][balance -1])
                            dp[i][j][balance] = true;

                        // right
                        if(j > 0 && balance > 0 && dp[i][j-1][balance - 1])
                            dp[i][j][balance] = true;
                    } else {
                        if(balance + 1 <= len) {
                            // down
                            if(i > 0 && dp[i-1][j][balance + 1])
                                dp[i][j][balance] = true;
                            
                            // right
                            if(j > 0 && dp[i][j-1][balance + 1])
                                dp[i][j][balance] = true;
                        }
                    }
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};