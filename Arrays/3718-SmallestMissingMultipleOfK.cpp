/*
    Given an integer array nums & an integer k, return the smallest positive multiple of k that is missing from nums. A multiple of k is any positive integer divisible by k

    Example 1:
    Input: nums = [8,2,3,4,6], k = 2
    Output: 10
    Explanation: The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;

        int ans = -1;
        int inc = k;

        while(true) {
            if(mp.find(k) == mp.end()) {
                ans = k;
                break;
            }

            k += inc;
        } 

        return ans;
    }
};