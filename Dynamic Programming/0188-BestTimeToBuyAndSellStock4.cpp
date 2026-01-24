/*
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k. Find the maximum profit you can achieve. You may 
    complete at most k transactions: i.e. you may buy at most k times and sell at most k times. Note: You may not engage in multiple transactions simultaneously (i.e., you must 
    sell the stock before you buy again).

    Example 1:
    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int canBuy, vector<int>& prices, vector<vector<vector<int>>>& dp, int transactions) {
        if(transactions == 0)
            return 0;

        if(idx == prices.size())
            return 0;

        if(dp[idx][canBuy][transactions] != -1)
            return dp[idx][canBuy][transactions];

        int profit = 0;

        if(canBuy) {
            int    buy = -prices[idx] + solve(idx+1, 0, prices, dp, transactions);
            int notBuy = solve(idx+1, 1, prices, dp, transactions);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[idx] + solve(idx+1, 1, prices, dp, transactions-1);
            int noSell = 0 + solve(idx+1, 0, prices, dp, transactions);
            profit = max(sell, noSell);
        }

        return dp[idx][canBuy][transactions] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        int tr = k;

        return solve(0, 1, prices, dp, tr);
    }
};