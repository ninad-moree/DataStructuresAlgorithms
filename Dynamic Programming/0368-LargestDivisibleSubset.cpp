/*
    Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or answer[j] % answer[i] == 0. If there are multiple solutions, return any of them.

    Example 1:
    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxi = 0;
        int lastIdx = 0;
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        
        for(int i=0; i<n; i++)
            hash[i] = i;
        
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[i]%nums[prev] == 0  && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIdx = i;
            }

            maxi = max(maxi, dp[i]);
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};