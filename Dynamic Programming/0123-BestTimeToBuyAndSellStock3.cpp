/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. You may complete at most two 
    transactions. Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        int tr = 2;

        return solve(0, 1, prices, dp, tr);
    }
};