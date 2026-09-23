/*
    Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

    Example 1:
    Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    Output: 3
    Explanation: The repeated subarray with maximum length is [3,2,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i == nums1.size() || j == nums2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(nums1[i] == nums2[j]) 
            return dp[i][j] = 1 + solve(i+1, j+1, nums1, nums2, dp);
        
        return dp[i][j] = 0;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));    
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                ans = max(ans, solve(i, j, nums1, nums2, dp));
        }    

        return ans;
    }
};