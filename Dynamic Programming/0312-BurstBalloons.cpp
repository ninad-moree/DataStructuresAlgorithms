/*
    You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons. If you 
    burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
    Return the maximum coins you can collect by bursting the balloons wisely.

    Example 1:
    Input: nums = [3,1,5,8]
    Output: 167
    Explanation:
    nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
    coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* TOP DOWN APPROACH - MEMOIZATION */
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;

        for(int k=i; k<=j; k++) {
            int cost = nums[i-1] * nums[k] * nums[j+1] + solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
    
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(1, n, nums, dp);
    }
};