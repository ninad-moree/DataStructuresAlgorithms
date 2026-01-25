/*
    Given an integer array nums, return the length of the longest strictly increasing subsequence.

    Example 1:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if(idx == nums.size())
            return 0;

        if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];
        
        int notTake = 0 + solve(idx+1, prev, nums, dp); 

        int take=0;
        if(prev == -1 || nums[idx] > nums[prev]) 
            take = 1 + solve(idx+1, idx, nums, dp); 
        
        return dp[idx][prev+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(0, -1, nums, dp);
    }
};