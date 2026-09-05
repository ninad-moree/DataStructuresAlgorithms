/*
    You are given an integer n. In one operation, you may split an integer x into two positive integers a and b such that a + b = x. The cost of this operation is a * b.
    Return an integer denoting the minimum total cost required to split the integer n into n ones.

    Example 1:
    Input: n = 3
    Output: 3
    Explanation: One optimal set of operations is:
    x	a	b	a + b	a * b	Cost
    3	1	2	3	     2	     2
    2	1	1	2	     1	     1
    Thus, the minimum total cost is 2 + 1 = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n == 1)
            return 0;

        if(dp[n] != -1)
            return dp[n];
        
        int minCost = INT_MAX;

        for(int i=1; i<=(n/2); i++) {
            int x = i;
            int y = n-i;

            int cost = x * y + solve(x, dp) + solve(y, dp);
            minCost = min(minCost, cost);
        }

        return dp[n] = minCost;
    }

    int minCost(int n) {
        vector<int> dp(501, -1);

        return solve(n, dp);
    }
};