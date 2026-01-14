/*
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the 
    coins, return -1. You may assume that you have an infinite number of each kind of coin.

    Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(index == 0) {
            if(amount % coins[index] == 0)
                return  amount /  coins[index];
            else
                return 1e9;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int notTake = solve(index-1, amount, coins, dp);
        int take = 1e9;
        if(amount >= coins[index]) 
            take = 1 + solve(index, amount - coins[index], coins, dp);
        

        return dp[index][amount] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        int ans = solve(n-1, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};