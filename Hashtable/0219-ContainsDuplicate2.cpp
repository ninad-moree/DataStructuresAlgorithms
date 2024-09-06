/*
    Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and 
    abs(i - j) <= k.

    Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) {
                if(abs(i - mp[nums[i]]) <= k)
                    return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};