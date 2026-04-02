/*
    You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either 
    right or down at any point in time. The grid contains a value coins[i][j] in each cell:
    If coins[i][j] >= 0, the robot gains that many coins.
    If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
    The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.
    Note: The robot's total coins can be negative. Return the maximum profit the robot can gain on the route.

    Example 1:
    Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
    Output: 8
    Explanation: An optimal path for maximum coins is:
    Start at (0, 0) with 0 coins (total coins = 0).
    Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
    Move to (1, 1), where there's a robber stealing 2 coins. The robot uses one neutralization here, avoiding the robbery (total coins = 1).
    Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
    Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        int n = coins.size();
        int m = coins[0].size(); 

        if(i >= n || j >= m)
            return INT_MIN;

        if(i == n-1 && j == m-1)
            return k > 0 ? max(0, coins[i][j]) : coins[i][j];

        if(dp[i][j][k] != INT_MIN)
            return dp[i][j][k];
        
        int right = solve(i+1, j, k, coins, dp);
        int down = solve(i, j+1, k, coins, dp);

        int ans = coins[i][j] + max(right, down);

        if(k > 0 && coins[i][j] < 0) {
            int rightN = solve(i+1, j, k-1, coins, dp);
            int downN  = solve(i, j+1, k-1, coins, dp);

            ans = max(ans, max(rightN, downN));
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        return solve(0, 0, 2, coins, dp);
    }
};