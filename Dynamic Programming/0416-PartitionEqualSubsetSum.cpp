/*
    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal
    or false otherwise.

    Example 1:
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (sum == 0)
            return true;
        if (index == 0)
            return arr[0] == sum;

        if (dp[index][sum] != -1)
            return dp[index][sum];

        bool notTake = solve(index - 1, sum, arr, dp);
        bool take = false;

        if (sum >= arr[index])
            take = solve(index - 1, sum - arr[index], arr, dp);

        return dp[index][sum] = (notTake || take);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        if(sum % 2 == 1)
            return false;

        int target = sum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(n-1, target, nums, dp);
    }
};