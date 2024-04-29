/*
    Given an integer array nums where every element appears three times except for one, which appears exactly once. 
    Find the single element and return it.

    Example 1:
    Input: nums = [2,2,3,2]
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=2;i<nums.size();i=i+3) {
            if(nums[i-2] != nums[i])
                return nums[i-2];
        }
        return nums[nums.size()-1];
    }

    int singleNumber2(vector<int>& nums) {
        int res = 0;

        for(auto i : nums)
            res ^= i;

        return res;
    }
};