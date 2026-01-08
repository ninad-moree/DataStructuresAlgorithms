/*
    Given two arrays nums1 and nums2. Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length. A subsequence of a array is a new array 
    which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a 
    subsequence of [1,2,3,4,5] while [1,5,3] is not).

    Example 1:
    Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
    Output: 18
    Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2. Their dot product is (2*3 + (-2)*(-6)) = 18.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i >= nums1.size() || j >= nums2.size())
            return -1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        int prod = INT_MIN;

        int takeBoth = solve(i+1, j+1, nums1, nums2, dp);
        int skip1 = solve(i+1, j, nums1, nums2, dp); // skips from array nums1 and takes from nums2
        int skip2 = solve(i, j+1, nums1, nums2, dp); // skips from array nums2 and takes from nums1

        prod = max(prod, nums1[i] * nums2[j] + max(0, takeBoth));
        prod = max(prod, skip1);
        prod = max(prod, skip2);

        return dp[i][j] = prod;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(501, vector<int>(501, -1));

        solve(0, 0, nums1, nums2, dp);

        return dp[0][0];
    }
};