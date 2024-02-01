/*
    You are given a 0-indexed integer array nums.
    Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all 
    such triplets have a negative value, return 0.
    The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

    Example 1:
    Input: nums = [12,6,1,2,7]
    Output: 77
    Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
    It can be shown that there are no ordered triplets of indices with a value greater than 77. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;

        vector<int> prefix_max(nums.size(), 0);
        vector<int> suffix_max(nums.size(), 0);

        prefix_max[0] = nums[0];
        suffix_max[nums.size()-1] = nums[nums.size()-1];

        for(int i=1; i<nums.size(); i++) 
            prefix_max[i] = max(prefix_max[i-1], nums[i]);

        for(int i=nums.size()-2; i>=0; i--) 
            suffix_max[i] = max(suffix_max[i+1], nums[i]);
        
        for(int i=1; i<nums.size()-1; i++) 
            ans = max(ans, (long long)(prefix_max[i-1] - nums[i]) * suffix_max[i+1] );
        
        return ans;
    }
};