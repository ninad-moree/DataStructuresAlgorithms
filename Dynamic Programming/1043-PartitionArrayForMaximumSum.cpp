/*
    Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the 
    maximum value of that subarray. Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

    Example 1:
    Input: arr = [1,15,7,9,2,5,10], k = 3
    Output: 84
    Explanation: arr becomes [15,15,15,9,10,10,10]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if(idx == arr.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int maxi = INT_MIN;
        int len = 0;
        int maxAns = INT_MIN;

        for(int j=idx; j<min(n, idx+k); j++) {
            len++;
            maxi = max(maxi, arr[j]);

            int sum = (len * maxi) + solve(j+1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[idx] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return solve(0, arr, k, dp);
    }
};