/*
    You are given an integer array nums of length n and an integer k. You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact 
    same subarray (same l and r) can be chosen more than once. The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]). The total value is the sum of
    the values of all chosen subarrays. Return the maximum possible total value you can achieve.

    Example 1:
    Input: nums = [1,3,2], k = 2
    Output: 4
    Explanation: One optimal approach is: Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
    Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2. Adding these gives 2 + 2 = 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;

        int mini = nums[0];
        int maxi = nums[0];

        for(int i=0; i<nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        ans = abs(mini - maxi);
        ans = ans * k;

        return ans;
    }
};