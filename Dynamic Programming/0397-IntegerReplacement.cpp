/*
    Given a positive integer n, you can apply one of the following operations: If n is even, replace n with n / 2. If n is odd, replace n with either n + 1 or n - 1.
    Return the minimum number of operations needed for n to become 1.

    Example 1:
    Input: n = 8
    Output: 3
    Explanation: 8 -> 4 -> 2 -> 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(long long n, unordered_map<long long, int>& dp) {
        if(n == 1)
            return 0;

        if(dp.find(n) != dp.end())
            return dp[n];

        int ans = INT_MAX;

        int even = INT_MAX;
        int odd1 = INT_MAX;
        int odd2 = INT_MAX;

        if(n % 2 == 0)
            even = solve(n/2, dp);
        else {
            odd1 = solve(n+1, dp);
            odd2 = solve(n-1, dp);
        }

        return dp[n] = 1 + min({even, odd1, odd2});
    }

    int integerReplacement(int n) {
        unordered_map<long long, int> dp;
        return solve((long long)n, dp);
    }
};