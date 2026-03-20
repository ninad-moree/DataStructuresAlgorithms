/*
    Alice and Bob take turns playing a game, with Alice starting first. Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting 
    of: Choosing any integer x with 0 < x < n and n % x == 0. Replacing the number n on the chalkboard with n - x.
    Also, if a player cannot make a move, they lose the game. Return true if and only if Alice wins the game, assuming both players play optimally.

    Example 1:
    Input: n = 2
    Output: true
    Explanation: Alice chooses 1, and Bob has no more moves.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int n, vector<int>& dp) {
        if(n == 1)
            return false;

        if(dp[n] != -1)
            return dp[n];

        unordered_set<int> factors;
        factors.insert(1);

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                factors.insert(i);
                if(i * i != n)
                    factors.insert(n / i);
            }
        }

        for(auto f : factors) {
            if(!solve(n - f, dp))
                return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};