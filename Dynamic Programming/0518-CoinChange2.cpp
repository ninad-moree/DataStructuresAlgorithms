/*
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the number of
    combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0. You may assume that you have an infinite number of
    each kind of coin. The answer is guaranteed to fit into a signed 32-bit integer.

    Example 1:
    Input: amount = 5, coins = [1,2,5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(index == 0) {
            if(amount % coins[index] == 0)
                return 1;
            else
                return 0;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int notTake = solve(index-1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[index]) 
            take = solve(index, amount - coins[index], coins, dp);
        

        return dp[index][amount] = notTake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = solve(n-1, amount, coins, dp);

        return ans;
    }
};