/*
    Given a circular array nums, find the maximum absolute difference between adjacent elements.

    Example 1:
    Input: nums = [1,2,4]
    Output: 3
    Explanation: Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size()-1; i++) 
            ans = max(ans, abs(nums[i] - nums[i+1]));
        
        ans = max(ans, abs(nums[0] - nums[nums.size()-1]));

        return ans;
    }
};