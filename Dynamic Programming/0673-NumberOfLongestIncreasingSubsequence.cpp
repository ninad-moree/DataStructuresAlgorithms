/*
    Given an integer array nums, return the number of longest increasing subsequences. Notice that the sequence has to be strictly increasing.

    Example 1:
    Input: nums = [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequences are [1, 3, 4, 7]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        int maxLen = 0;
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                } else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                    cnt[i] += cnt[prev];
            }

            maxLen = max(maxLen, dp[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxLen)
                ans += cnt[i];
        }

        return ans;
    }
};