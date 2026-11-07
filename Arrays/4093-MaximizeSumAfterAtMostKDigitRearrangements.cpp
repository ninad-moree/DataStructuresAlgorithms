/*
    You are given an integer array nums of length n and an integer k. In one operation, you may choose any element of nums and rearrange its decimal digits in any order to form
    a new integer. Return the maximum possible sum of the array after performing at most k operations.

    Example 1:
    Input: nums = [123,45], k = 1
    Output: 366
    Explanation: We choose nums[0] = 123 and rearrange its digits to form 321. The array becomes [321, 45]. Thus, the total sum is 321 + 45 = 366.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

        vector<int> gains;

        for(int i=0; i<n; i++) {
            string num = to_string(nums[i]);
            sort(num.rbegin(), num.rend());

            int best = stoi(num);
            gains.push_back(best - nums[i]);

            ans += nums[i];
        }

        sort(gains.rbegin(), gains.rend());

        for(int i=0; i<k; i++)
            ans += gains[i];

        return ans;
    }
};