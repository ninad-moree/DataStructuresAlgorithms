/*
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell 
    the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
    Find and return the maximum profit you can achieve.

    Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        next[0] = next[1] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0;

                if(buy) {
                    int buy = -prices[i] + next[0];
                    int noBuy = 0 + next[1];
                    profit = max(buy, noBuy);
                } else {
                    int sell = prices[i] + next[1];
                    int noSell = 0 + next[0];
                    profit = max(sell, noSell);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

    int maxProfit2(vector<int>& prices) {
        int ans = 0;
        int profit = 0;
        int buy = 0;

        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1] && prices[i] > prices[buy]) {
                profit = prices[i] - prices[i-1];
                ans += profit;
            } else
                buy = i;
        }

        return ans;
    }
};