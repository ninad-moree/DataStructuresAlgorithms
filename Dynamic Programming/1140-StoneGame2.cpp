/*
    Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The 
    objective of the game is to end with the most stones. Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take all the stones in the 
    first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1. The game continues until all the stones have been taken. Assuming Alice and Bob 
    play optimally, return the maximum number of stones Alice can get.

    Example 1:
    Input: piles = [2,7,9,4,4]
    Output: 10
    Explanation: If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total. If Alice takes two 
    piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total. So we return 10 since it's larger.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int M, vector<int>& piles, vector<vector<int>>& dp) {
        if(idx >= piles.size())
            return 0;

        if(dp[idx][M] != -1)
            return dp[idx][M];

        int best = INT_MIN;
        int sum = 0;

        for(int X=1; X<=2*M && idx + X <= piles.size(); X++) {
            sum += piles[idx + X - 1];
            best = max(best, sum - solve(idx+X, max(X, M), piles, dp));
        }

        return dp[idx][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        int total = 0;

        for(auto i : piles)
            total += i;
        
        // total = alice + bob
        // diff = alice - bob
        // therefore alice = (total + diff) / 2
        int diff = solve(0, 1, piles, dp);

        return (total + diff) / 2;
    }
};