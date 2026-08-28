/*
    You are given a 2D integer array items, where items[i] = [factori, pricei] represents the ith item. You are also given an integer budget. There are unlimited copies of each
    item available for purchase.You may buy any number of copies of any items such that the total cost of the purchased copies is at most budget. After buying items, you may 
    receive free copies according to the following rules: For each item i that you bought at least one copy of, you receive one free copy of every item j such that j != i and 
    factori divides factorj. Buying multiple copies of the same item i does not give additional free copies through item i. The same item j can be received multiple times for 
    free if it is received from purchases of different item types. Return the maximum total number of item copies you can obtain, including both purchased copies and free 
    copies, while spending at most budget on purchased items.

    Example 1:
    Input: items = [[6,2],[2,6],[3,4]], budget = 9
    Output: 4
    Explanation: You can buy 2 copies of item 0 and 1 copy of item 2 for a total cost of 2 * 2 + 4 = 8, which is not greater than budget = 9. Buying item 2 gives 1 free copy of
    item 0, because factor2 = 3 divides factor0 = 6. You leave with 3 purchased copies and 1 free copy, for a total of 4 item copies.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int budget, int mini, vector<vector<int>>& items, vector<int>& free, vector<vector<int>>& dp) {
        if(idx >= items.size())
            return budget / mini; // if budget is still remaining -> take the item with min cost
        
        if(dp[idx][budget] != -1)
            return dp[idx][budget];

        int take = 0;

        if(budget >= items[idx][1]) 
            take = free[idx] + solve(idx+1, budget - items[idx][1], mini, items, free, dp);
        
        int notTake = solve(idx+1, budget, mini, items, free, dp);

        return dp[idx][budget] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mini = INT_MAX;
        vector<int> free(n);

        vector<vector<int>> dp(n, vector<int>(budget+1, -1));

        for(int i=0; i<n; i++) {
            mini = min(mini, items[i][1]);

            for(int j=0; j<n; j++) {
                if(items[j][0] % items[i][0] == 0) // this insures the free[i] contains --> the item itself as well as the free items we can recevie
                    free[i]++;
            }
        }

        return solve(0, budget, mini, items, free, dp);
    }
};