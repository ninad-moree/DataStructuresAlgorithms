/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee. Find the maximum profit you 
    can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
    The transaction fee is only charged once for each stock purchase and sale.

    Example 1:
    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: The maximum profit can be achieved by:
    - Buying at prices[0] = 1
    - Selling at prices[3] = 8
    - Buying at prices[4] = 4
    - Selling at prices[5] = 9
    The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int canBuy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx >= prices.size())
            return 0;

        int profit = 0;

        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];

        if(canBuy) {
            int buy = -prices[idx] + solve(idx+1, 0, fee, prices, dp);
            int noBuy = 0 + solve(idx+1, 1, fee, prices, dp);
            profit = max(buy, noBuy);
        } else {
            int sell = prices[idx] - fee + solve(idx+1, 1, fee, prices, dp);
            int noSell = 0 + solve(idx+1, 0, fee, prices, dp);
            profit = max(sell, noSell);
        }

        return dp[idx][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, fee, prices, dp);
    }
};