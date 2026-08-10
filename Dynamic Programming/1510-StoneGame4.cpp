/*
    Alice and Bob take turns playing a game, with Alice starting first. Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of 
    removing any non-zero square number of stones in the pile. Also, if a player cannot make a move, he/she loses the game. Given a positive integer n, return true if and only 
    if Alice wins the game otherwise return false, assuming both players play optimally.

    Example 1:
    Input: n = 1
    Output: true
    Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int n, vector<int>& dp) {
        if (n == 0) 
            return false;   

        if (dp[n] != -1) 
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            bool prevAns = solve(n - i * i, dp);
            if (!prevAns) 
                return dp[n] = true;        // found a move that puts opponent in a losing state
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};