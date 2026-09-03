/*
    You are given an integer array nums of length n. An index i (0 < i < n - 1) is special if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]. You may perform operations where 
    you choose any index i and increase nums[i] by 1. Your goal is to: Maximize the number of special indices. Minimize the total number of operations required to achieve that 
    maximum. Return an integer denoting the minimum total number of operations required.

    Example 1:
    Input: nums = [1,2,2]
    Output: 1
    Explanation:​​​​​​​ Start with nums = [1, 2, 2]. Increase nums[1] by 1, array becomes [1, 3, 2]. The final array is [1, 3, 2] has 1 special index, which is the maximum achievable.
    It is impossible to achieve this number of special indices with fewer operations. Thus, the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, long long> solve(int idx, vector<int>& nums, vector<pair<int, long long>>& dp) {
        if(idx >= nums.size()-1)
            return {0, 0};

        if(dp[idx].first != -1)
            return dp[idx];

        // dont make idx speical
        auto notTake = solve(idx+1, nums, dp);

        // make idx special
        long long ope = max(nums[idx-1], nums[idx+1]) + 1LL - nums[idx];
        ope = max(ope, 0LL); // already speical

        auto take = solve(idx+2, nums, dp);

        take.first++;
        take.second += ope;

        if(take.first > notTake.first)
            return dp[idx] = take;
        
        if(take.first < notTake.first)
            return dp[idx] = notTake;

        return dp[idx] = min(take, notTake);
    }

    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, long long>> dp(n, {-1, -1}); // {max no of special idx, min operations needed}

        return solve(1, nums, dp).second;
    }
};