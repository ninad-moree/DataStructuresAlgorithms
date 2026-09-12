/*
    You are given an integer array nums of length n. Choose an index i such that 0 <= i < n - 1. For a chosen split index i:
    Let prefixSum(i) be the sum of nums[0] + nums[1] + ... + nums[i]. Let suffixMin(i) be the minimum value among nums[i + 1], nums[i + 2], ..., nums[n - 1].
    The score of a split at index i is defined as: score(i) = prefixSum(i) - suffixMin(i). Return an integer denoting the maximum score over all valid split indices.

    Example 1:
    Input: nums = [10,-1,3,-4,-5]
    Output: 17
    Explanation: The optimal split is at i = 2, score(2) = prefixSum(2) - suffixMin(2) = (10 + (-1) + 3) - (-5) = 17.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        vector<long long> suffix(n);

        prefix[0] = nums[0];

        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1] + nums[i];

        suffix[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--) 
            suffix[i] = min(suffix[i+1], 1LL * nums[i]);

        long long score = LLONG_MIN;

        for(int i=0; i<n-1; i++)
            score = max(score, prefix[i] - suffix[i+1]);

        return score;
    }
};