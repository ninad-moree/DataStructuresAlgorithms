/*
    You have n dice, and each dice has k faces numbered from 1 to k. Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll
    the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

    Example 1:
    Input: n = 1, k = 6, target = 3
    Output: 1
    Explanation: You throw one die with 6 faces. There is only one way to get a sum of 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int n, int k, int target, vector<vector<int>>& dp) {
        if(n == 0 && target == 0) 
            return 1;
        if(n == 0 || target <= 0)
            return 0;

        if(dp[n][target] != -1)
            return dp[n][target] % MOD;

        long long ways = 0;
        for(int i=1; i<=k; i++) 
            ways += solve(n-1, k, target - i, dp) % MOD;

        return dp[n][target] = ways % MOD;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));

        return solve(n, k, target, dp);
    }
};