/*
    Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements: Choose the first two elements of nums and 
    delete them. Choose the last two elements of nums and delete them. Choose the first and the last elements of nums and delete them. The score of the operation is the sum of 
    the deleted elements. Your task is to find the maximum number of operations that can be performed, such that all operations have the same score. Return the maximum number of
    operations possible that satisfy the condition mentioned above.

    Example 1:
    Input: nums = [3,2,1,2,3,4]
    Output: 3
    Explanation: We perform the following operations: - Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4]. - Delete the first and the last elements, with 
    score 1 + 4 = 5, nums = [2,3]. - Delete the first and the last elements, with score 2 + 3 = 5, nums = []. We are unable to perform any more operations as nums is empty.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, int sum, vector<vector<int>>& dp) {
        if(j - i + 1 < 2)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int firstTwo = 0;
        if(sum == -1 || sum == nums[i] + nums[i+1])
            firstTwo = 1 + solve(i+2, j, nums, nums[i] + nums[i+1], dp);
        
        int lastTwo = 0;
        if(sum == -1 || sum == nums[j] + nums[j-1])
            lastTwo = 1 + solve(i, j-2, nums, nums[j] + nums[j-1], dp);

        int firstAndLast = 0;
        if(sum == -1 || sum == nums[i] + nums[j]) 
            firstAndLast = 1 + solve(i+1, j-1, nums, nums[i] + nums[j], dp);

        return dp[i][j] = max({firstTwo, lastTwo, firstAndLast});
    }

    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, nums, -1, dp);
    }
};