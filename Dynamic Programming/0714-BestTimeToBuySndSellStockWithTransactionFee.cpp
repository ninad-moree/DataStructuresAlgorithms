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
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        int profit = 0;

        for(int i=n-1; i>=0; i--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                if(canBuy) {
                    int buy = -prices[i] + dp[i+1][0];
                    int notBuy = dp[i+1][1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = prices[i] - fee + dp[i+1][1];
                    int notSell = dp[i+1][0];
                    profit = max(sell, notSell);
                }

                dp[i][canBuy] = profit;
            }
        }

        return dp[0][1];
    }
};