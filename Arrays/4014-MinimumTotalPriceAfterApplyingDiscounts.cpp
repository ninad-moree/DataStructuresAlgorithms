/*
    You are given two integer arrays prices and discounts. The value prices[i] represents the price of the ith item, and discounts[j] represents a discount percentage.
    You may apply discounts subject to the following rules: Each discount can be applied to at most one item. Each item can receive at most one discount.
    An item may also receive no discount. If a discount of d percent is applied to an item with price p, its final price becomes (p * (100 - d)) / 100. The final price is 
    not rounded. Return the minimum possible sum of final prices after assigning discounts optimally. Answers within 10-5 of the actual answer will be accepted.

    Example 1:
    Input: prices = [10,30,21], discounts = [50,60]
    Output: 32.50000
    Explanation: Apply discounts[1] = 60 to prices[1] = 30, thus 30 * (100 - 60) / 100 = 12. Apply discounts[0] = 50 to prices[2] = 21, thus 21 * (100 - 50) / 100 = 10.5.
    prices[0] = 10 receives no discount, so it stays 10. The total is 12 + 10.5 + 10 = 32.50000, which is the minimum possible.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0.0;

        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int i = 0;
        int j = 0;

        while(i < prices.size() && j < discounts.size()) {
            double p = prices[i] - (prices[i] * discounts[j]) / 100.0;
            ans += p;

            i++;
            j++;
        }

        while(i < prices.size()) {
            ans += prices[i];
            i++;
        }

        return ans;
    }
};