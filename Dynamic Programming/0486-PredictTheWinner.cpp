/*
    You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2. Player 1 and player 2 take turns, with player 1 starting first. 
    Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which 
    reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array. Return true if Player 1 can
    win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing 
    optimally.

    Example 1:
    Input: nums = [1,5,2]
    Output: false
    Explanation: Initially, player 1 can choose between 1 and 2.  If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will
    be left with 1 (or 2). So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.  Hence, player 1 will never be the winner and you need to return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == j)
            return nums[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = nums[i] - solve(i + 1, j, nums, dp);
        int takeRight = nums[j] - solve(i, j - 1, nums, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n, -1));

        return solve(0, nums.size() - 1, nums, dp) >= 0;
    }
};