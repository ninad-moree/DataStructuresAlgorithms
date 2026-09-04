/*
    You are given an integer array nums and an integer target. You may remove any number of elements from nums (possibly zero). Return the minimum number of removals required 
    so that the bitwise XOR of the remaining elements equals target. If it is impossible to achieve target, return -1. The bitwise XOR of an empty array is 0.

    Example 1:
    Input: nums = [1,2,3], target = 2
    Output: 1
    Explanation: Removing nums[1] = 2 leaves [nums[0], nums[2]] = [1, 3]. The XOR of [1, 3] is 2, which equals target. It is not possible to achieve XOR = 2 in less than one 
    removal, therefore the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(idx >= nums.size()) {
            if(target == 0)
                return 0;
            return INT_MIN;
        }

        if(dp[idx][target] != -1)
            return dp[idx][target];

        int take = 1 + solve(idx+1, nums, target ^ nums[idx], dp);
        int notTake = solve(idx+1, nums, target, dp);

        return dp[idx][target] = max(take, notTake);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int maxi = 1 << 14;

        if(n == 0){
            if(target == 0)
                return true;
            return false;
        }

        // max subset size using elements from i to end with XOR = target
        vector<vector<int>> dp(n+1, vector<int>(maxi, -1));

        int size = solve(0, nums, target, dp);

        if(size < 0)
            return -1;
        return n - size;
    }
};