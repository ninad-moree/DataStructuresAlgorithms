/*
    On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), 
    and the bottom-right cell is (n - 1, n - 1). A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then
    one cell in an orthogonal direction. Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the 
    chessboard) and moves there. The knight continues moving until it has made exactly k moves or has moved off the chessboard. Return the probability that the knight remains 
    on the board after it has stopped moving.

    Example 1:
    Input: n = 3, k = 2, row = 0, column = 0
    Output: 0.06250
    Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board. From each of those positions, there are also two moves that will keep the knight 
    on the board. The total probability the knight stays on the board is 0.0625.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double solve(int i, int j, int moves, int n, vector<pair<int, int>>& directions, vector<vector<vector<double>>>& dp) {
        if(moves == 0)
            return 1.0;

        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];

        double ans = 0;

        for(auto d : directions) {
            int px = i + d.first;
            int py = j + d.second;

            if(px >= 0 && px < n && py >= 0 && py < n) 
                ans += solve(px, py, moves - 1, n, directions, dp) / 8.0;
        }

        return dp[i][j][moves] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));

        return solve(row, column, k, n, directions, dp);
    }
};