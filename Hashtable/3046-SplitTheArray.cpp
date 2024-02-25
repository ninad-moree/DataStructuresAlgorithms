/*
    You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that
    nums1.length == nums2.length == nums.length / 2.
    nums1 should contain distinct elements.
    nums2 should also contain distinct elements.
    Return true if it is possible to split the array, and false otherwise.

    Example 1:
    Input: nums = [1,1,2,2,3,4]
    Output: true
    Explanation: One of the possible ways to split nums is nums1 = [1,2,3] and nums2 = [1,2,4].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i : nums)
            mp[i]++;
        
        for(auto i : mp) {
            if(i.second > 2)
                return false;
        }

        return true;
    }
};