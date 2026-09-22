/*
    An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer n, return the nth ugly number.

    Example 1:
    Input: n = 10
    Output: 12
    Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0)
            return 0;
        
        if(n==1)
            return 1;

        vector<int> ans(n);
        ans[0] = 1;

        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        for(int i=1; i<n; i++) {
            ans[i] = min(ans[p2]*2, min(ans[p3]*3, ans[p5]*5));

            if(ans[i] == ans[p2]*2)
                p2++;
            if(ans[i] == ans[p3]*3)
                p3++;
            if(ans[i] == ans[p5]*5)
                p5++;
        }

        return ans[n-1];
    }


    /* MEMOIZATION DP*/

    long long solve(int n, vector<long long>& dp) {
        if(n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];

        long long ans = LLONG_MAX;

        for(int i=1; i<n; i++) {
            long long x = solve(i, dp);

            if(x * 2 > solve(n-1, dp))
                ans = min(ans, x * 2);
            
            if(x * 3 > solve(n-1, dp))
                ans = min(ans, x * 3);

            if(x * 5 > solve(n-1, dp))
                ans = min(ans, x * 5);
        }

        return dp[n] = ans;
    }

    int nthUglyNumber2(int n) {
        // dp[n] = nth ugly number.
        vector<long long> dp(n+1, -1);

        return solve(n, dp);
    }
};