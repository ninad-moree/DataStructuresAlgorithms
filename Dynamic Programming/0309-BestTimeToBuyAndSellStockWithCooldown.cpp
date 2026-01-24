/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. You may complete as many transactions as
    you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions: After you sell your stock, you cannot buy stock on the next day 
    (i.e., cooldown one day). Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: prices = [1,2,3,0,2]
    Output: 3
    Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx >= prices.size())
            return 0;

        int profit = 0;

        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];

        if(canBuy) {
            int buy = -prices[idx] + solve(idx+1, 0, prices, dp);
            int noBuy = 0 + solve(idx+1, 1, prices, dp);
            profit = max(buy, noBuy);
        } else {
            int sell = prices[idx] + solve(idx+2, 1, prices, dp);
            int noSell = 0 + solve(idx+1, 0, prices, dp);
            profit = max(sell, noSell);
        }

        return dp[idx][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
};