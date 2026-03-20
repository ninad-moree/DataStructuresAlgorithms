/*
    A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be 
    either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences. For example, [1, 7, 4, 9, 2, 5] is a wiggle
    sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative. In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first
    is not because its first two differences are positive, and the second is not because its last difference is zero. A subsequence is obtained by deleting some elements (possibly
    zero) from the original sequence, leaving the remaining elements in their original order. Given an integer array nums, return the length of the longest wiggle subsequence of 
    nums.

    Example 1:
    Input: nums = [1,7,4,9,2,5]
    Output: 6
    Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // diff = 0(not started), diff = 1(positive diff), diff=-1(negative diff)
    int solve(int idx, int prevIdx, int diff, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if(idx == nums.size())
            return 0;

        if (dp[idx][prevIdx+1][diff+1] != -1) 
            return dp[idx][prevIdx+1][diff+1];

        int notTake = solve(idx+1, prevIdx, diff, nums, dp);

        int take = 0;
        if(prevIdx == -1)
            take = 1 + solve(idx+1, idx, 0, nums, dp);
        else {
            int difference = nums[idx] - nums[prevIdx];

            if(difference > 0 && diff != 1)
                take = 1 + solve(idx+1, idx, 1, nums, dp);
            else if(difference < 0 && diff != -1)
                take = 1 + solve(idx+1, idx, -1, nums, dp);
        }

        return dp[idx][prevIdx+1][diff+1] = max(take, notTake);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(3, -1)));
        return solve(0, -1, 0, nums, dp);
    }
};