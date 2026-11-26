/*
    You are given an integer array nums. The alternating sum of nums is the value obtained by adding elements at even indices and subtracting elements at odd indices. That is, 
    nums[0] - nums[1] + nums[2] - nums[3]... Return an integer denoting the alternating sum of nums.

    Example 1:
    Input: nums = [1,3,5,7]
    Output: -4
    Explanation: Elements at even indices are nums[0] = 1 and nums[2] = 5 because 0 and 2 are even numbers. Elements at odd indices are nums[1] = 3 and nums[3] = 7 because 1 
    and 3 are odd numbers. The alternating sum is nums[0] - nums[1] + nums[2] - nums[3] = 1 - 3 + 5 - 7 = -4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            if(i % 2 == 0)
                ans += nums[i];
            else
                ans -= nums[i];
        }

        return ans;
    }
};