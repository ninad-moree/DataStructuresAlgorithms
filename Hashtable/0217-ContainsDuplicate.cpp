/*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i : nums)
            mp[i]++;

        for(auto i : mp) {
            if(i.second > 1)
                return true;
        }

        return false;
    }
};