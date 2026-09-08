/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed and is protected by a security system with a color 
    code. You are given two integer arrays nums and colors, both of length n, where nums[i] is the amount of money in the ith house and colors[i] is the color code of that 
    house. You cannot rob two adjacent houses if they share the same color code. Return the maximum amount of money you can rob.

    Example 1:
    Input: nums = [1,4,3,5], colors = [1,1,2,2]
    Output: 9
    Explanation: Choose houses i = 1 with nums[1] = 4 and i = 3 with nums[3] = 5 because they are non-adjacent. Thus, the total amount robbed is 4 + 5 = 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int idx, bool prevTaken, vector<int>& nums, vector<int>& colors, vector<vector<long long>>& dp) {
        if(idx >= nums.size()) 
            return 0;

        if(dp[idx][prevTaken] != -1)
            return dp[idx][prevTaken];

        long long take = 0;
        if(!prevTaken || colors[idx] != colors[idx-1])
            take = nums[idx] + solve(idx+1, true, nums, colors, dp);

        long long notTake = solve(idx+1, false, nums, colors, dp);

        return dp[idx][prevTaken] = max(take, notTake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));

        return solve(0, false, nums, colors, dp);
    }
};