/*
    You are given an array of positive integers nums, and a positive integer k. You are allowed to perform an operation once on nums, where in each operation you can remove any
    non-overlapping prefix and suffix from nums such that nums remains non-empty. You need to find the x-value of nums, which is the number of ways to perform this operation so
    that the product of the remaining elements leaves a remainder of x when divided by k. Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= 
    k - 1. Note that the prefix and suffix to be chosen for the operation can be empty.

    Example 1:
    Input: nums = [1,2,3,4,5], k = 3
    Output: [9,2,4]
    Explanation: For x = 0, the possible operations include all possible ways to remove non-overlapping prefix/suffix that do not remove nums[2] == 3.
    For x = 1, the operations are: Remove the empty prefix and the suffix [2, 3, 4, 5]. nums becomes [1]. Remove the prefix [1, 2, 3] and the suffix [5]. nums becomes [4].
    For x = 2, the possible operations are: Remove the empty prefix and the suffix [3, 4, 5]. nums becomes [1, 2]. Remove the prefix [1] and the suffix [3, 4, 5]. nums becomes 
               [2]. Remove the prefix [1, 2, 3] and the empty suffix. nums becomes [4, 5]. Remove the prefix [1, 2, 3, 4] and the empty suffix. nums becomes [5].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int idx, int prod, int req, vector<int>& nums, int k, vector<vector<long long>>& dp) {
        if(idx == nums.size())
            return 0;

        if(dp[idx][prod + 1] != -1)
            return dp[idx][prod + 1];

        long long take = 0;
        long long notTake = 0;
        long long cnt = 0;

        if(prod == -1) {
            // if we haven't taken any number yet, we can either take the current number or skip it
            if(nums[idx] == req)
                cnt = 1;
            
            take = cnt + solve(idx+1, nums[idx], req, nums, k, dp);
            notTake = solve(idx+1, -1, req, nums, k, dp);
        } else {
            // extend the product with the current number and take mod k to avoid overflow
            int newProd = (nums[idx] * prod) % k;
            
            // if the new product matches the required remainder, we can count this as a valid way
            if(newProd == req)
                cnt = 1;
            
            take = cnt + solve(idx+1, newProd, req, nums, k, dp);
        }

        return dp[idx][prod + 1] = take + notTake;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);

        for(int i=0; i<n; i++)
            nums[i] = nums[i] % k;

        // for each possible remainder from 0 to k-1, calculate the number of ways to achieve that remainder
        for(int req=0; req<k; req++) {
            vector<vector<long long>> dp(n, vector<long long>(k+1, -1));
            ans[req] = solve(0, -1, req, nums, k, dp);
        }

        return ans;
    }
};