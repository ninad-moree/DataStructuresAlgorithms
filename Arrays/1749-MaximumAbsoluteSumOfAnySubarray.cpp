/*
    You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + 
    numsr).Return the maximum absolute sum of any (possibly empty) subarray of nums.
    Note that abs(x) is defined as follows:
    If x is a negative integer, then abs(x) = -x. If x is a non-negative integer, then abs(x) = x.

    Example 1:
    Input: nums = [1,-3,2,3,-4]
    Output: 5
    Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = 0;
        int sum1 = 0;
        int ans2 = 0;
        int sum2 = 0;

        for(int i=0; i<nums.size(); i++) {
            sum1 = max(nums[i], sum1 + nums[i]);
            ans1 = max(ans1, sum1);

            sum2 = min(nums[i], sum2 + nums[i]);
            ans2 = min(ans2, sum2);
        }

        return max(ans1, abs(ans2));
    }
};