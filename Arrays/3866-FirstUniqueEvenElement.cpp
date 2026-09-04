/*
    You are given an integer array nums. Return an integer denoting the first even integer (earliest by array index) that appears exactly once in nums. If no such integer 
    exists, return -1. An integer x is considered even if it is divisible by 2.

    Example 1:
    Input: nums = [3,4,2,5,4,6]
    Output: 2
    Explanation: Both 2 and 6 are even and they appear exactly once. Since 2 occurs first in the array, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) {
            if(i % 2 == 0)
                mp[i]++;
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2 == 0 && mp[nums[i]] == 1)
                return nums[i];
        }

        return -1;
    }
};