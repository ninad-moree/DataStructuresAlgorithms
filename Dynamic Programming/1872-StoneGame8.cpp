/*
    Alice and Bob take turns playing a game, with Alice starting first. There are n stones arranged in a row. On each player's turn, while the number of stones is more 
    than one, they will do the following:
    Choose an integer x > 1, and remove the leftmost x stones from the row. Add the sum of the removed stones' values to the player's score.
    Place a new stone, whose value is equal to that sum, on the left side of the row. The game stops when only one stone is left in the row.
    The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score 
    difference. Given an integer array stones of length n where stones[i] represents the value of the ith stone from the left, return the score difference between Alice and
    Bob if they both play optimally.

    Example 1:
    Input: stones = [-1,2,-3,4,-5]
    Output: 5
    Explanation: - Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of value 2 on the left. stones = [2,-5].
    - Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on the left. stones = [-3].
    The difference between their scores is 2 - (-3) = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, vector<int>& stones, vector<int>& dp) {
        if(idx == stones.size() - 1)
            return stones[idx];

        if(dp[idx] != INT_MIN)
            return dp[idx];

        int next = solve(idx+1, stones, dp);

        return dp[idx] = max(next, stones[idx] - next);
    }

    int stoneGameVIII(vector<int>& stones) {
        for(int i=1; i<stones.size(); i++)
            stones[i] += stones[i-1];

        vector<int> dp(stones.size(), INT_MIN);

        return solve(1, stones, dp);
    }
};