/*
    You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day. A smooth descent period of a stock 
    consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted 
    from this rule. Return the number of smooth descent periods.

    Example 1:
    Input: prices = [3,2,1,4]
    Output: 7
    Explanation: There are 7 smooth descent periods: [3], [2], [1], [4], [3,2], [2,1], and [3,2,1] Note that a period with one day is a smooth descent period by the definition.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();

        ans += n;

        int r = 1;
        long long curr = 0;

        while(r < n) {
            if(prices[r] == prices[r-1] - 1) {
                curr++;
                r++;
            } else {
                long long s = curr*(curr + 1)/2;
                ans += s;
                curr = 0;
                r = r + 1;
            }
        }

        ans += (curr) * (curr + 1) / 2;

        return ans;
    }
};