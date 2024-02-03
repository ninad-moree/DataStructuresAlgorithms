/*
    Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, 
    each subarray has their values changed to become the maximum value of that subarray.
    Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

    Example 1:
    Input: arr = [1,15,7,9,2,5,10], k = 3
    Output: 84
    Explanation: arr becomes [15,15,15,9,10,10,10]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int max_val = 0;
            for (int j = 1; j <= min(k, i); ++j) {
                max_val = max(max_val, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + max_val * j);
            }
        }

        return dp[n];
    }
};