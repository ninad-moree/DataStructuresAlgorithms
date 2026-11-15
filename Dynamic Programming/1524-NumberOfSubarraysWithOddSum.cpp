/*
    Given an array of integers arr, return the number of subarrays with an odd sum. Since the answer can be very large, return it modulo 109 + 7.

    Example 1:
    Input: arr = [1,3,5]
    Output: 4
    Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]. All sub-arrays sum are [1,4,9,3,8,5]. Odd sums are [1,9,3,5] so the answer is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int idx, int parity, vector<int>& arr, vector<vector<int>>& dp) {
        if(idx >= arr.size())
            return 0;

        if(dp[idx][parity] != -1)
            return dp[idx][parity];

        int newParity = (parity + arr[idx]) % 2;

        int take = (newParity == 1) + solve(idx + 1, newParity, arr, dp);
        int notTake = 0;

        return dp[idx][parity] = (take + notTake) % MOD;
    }

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(2, -1));

        for(int i=0; i<n; i++) {
            ans +=  solve(i, 0, arr, dp);
            ans %= MOD;
        }

        return ans;
    }
};