/*
    You are climbing a staircase with n + 1 steps, numbered from 0 to n. You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.
    From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2 You start from step 0 with cost
    = 0. Return the minimum total cost to reach step n.

    Example 1:
    Input: n = 4, costs = [1,2,3,4]
    Output: 13
    Explanation: One optimal path is 0 → 1 → 2 → 4 Thus, the minimum total cost is 2 + 3 + 8 = 13
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int n, vector<int>& costs, vector<int>& dp) {
        if(idx == n)
            return 0;

        if(idx > n)
            return 1e9;

        if(dp[idx] != -1)
            return dp[idx];

        int one = 1e9;
        int two = 1e9;
        int three = 1e9;

        if(idx < costs.size())
            one = costs[idx] + 1 + solve(idx + 1, n, costs, dp);

        if(idx + 1 < costs.size())
            two = costs[idx+1] + 4 + solve(idx + 2, n, costs, dp);

        if(idx + 2 < costs.size())
            three = costs[idx+2] + 9 + solve(idx + 3, n, costs, dp);

        return dp[idx] = min({one, two, three});
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return solve(0, n, costs, dp);
    }

/* ================================================================================= TOP DOWN ================================================================================ */ 

    int climbStairs2(int n, vector<int>& costs) {
        vector<long long> dp(n+1, 1e9);
        dp[0] = 0;

        for(int i=1; i<=n; i++) {
            dp[i] = costs[i - 1] + 1 + dp[i-1];

            // i -> i + 2
            if (i - 2 >= 0) 
                dp[i] = min(dp[i], (long long)costs[i - 1] + 4 + dp[i - 2]);

            // i -> i + 3
            if (i - 3 >= 0) 
                dp[i] = min(dp[i], (long long)costs[i - 1] + 9 + dp[i - 3]);
            
        }

        return dp[n];
    }
};
