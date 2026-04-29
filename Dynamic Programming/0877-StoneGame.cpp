/*
    Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The 
    objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties. Alice and Bob take turns, with Alice 
    starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, 
    at which point the person with the most stones wins. Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

    Example 1:
    Input: piles = [5,3,4,5]
    Output: true
    Explanation: 
    Alice starts first, and can only take the first 5 or the last 5. Say she takes the first 5, so that the row becomes [3, 4, 5].
    If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points. If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
    This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int start, int end, bool turn, vector<int>& piles, vector<vector<int>> &dp) {
        if(start > end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int firstAlice;
        int firstBob;
        if(turn) {
            int first = piles[start] + solve(start+1, end, false, piles, dp);
            int last = piles[end] + solve(start, end-1, false, piles, dp);

            firstAlice = max(first, last);
        } else {
            int first = piles[start] + solve(start+1, end, true, piles, dp);
            int last = piles[end] + solve(start, end-1, true, piles, dp);

            firstBob = max(first, last);
        }

        return dp[start][end] = max(firstAlice, firstBob);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, true, piles, dp);
    }
};