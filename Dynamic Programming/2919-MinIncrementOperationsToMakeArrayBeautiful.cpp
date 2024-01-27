/*
    You are given a 0-indexed integer array nums having length n, and an integer k.
    You can perform the following increment operation any number of times (including zero):
    Choose an index i in the range [0, n - 1], and increase nums[i] by 1.
    An array is considered beautiful if, for any subarray with a size of 3 or more, 
    its maximum element is greater than or equal to k.
    Return an integer denoting the minimum number of increment operations needed to make nums beautiful.

    Example 1:
    Input: nums = [2,3,0,0,2], k = 4
    Output: 3
    Explanation: We can perform the following increment operations to make nums beautiful:
    Choose index i = 1 and increase nums[1] by 1 -> [2,4,0,0,2].
    Choose index i = 4 and increase nums[4] by 1 -> [2,4,0,0,3].
    Choose index i = 4 and increase nums[4] by 1 -> [2,4,0,0,4].
    The subarrays with a size of 3 or more are: [2,4,0], [4,0,0], [0,0,4], [2,4,0,0], [4,0,0,4], [2,4,0,0,4].
    In all the subarrays, the maximum element is equal to k = 4, so nums is now beautiful.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long> dp(nums.size());

        int n = nums.size();    

        dp[0] = max(0, k-nums[0]);
        dp[1] = max(0, k-nums[1]);
        dp[2] = max(0, k-nums[2]);

        for(int i=3;i<nums.size();i++) 
            dp[i] = max(0, k-nums[i]) + min(dp[i-1], min(dp[i-2], dp[i-3]));

        return min(dp[n-1], min(dp[n-2], dp[n-3]));
    }
};