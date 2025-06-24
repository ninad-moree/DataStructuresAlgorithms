/*
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Input: nums = [1,1,1], k = 2
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;

        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];

            int target = sum - k;

            if(sum == k)
                cnt++;

            if(mp.find(target) != mp.end()) 
                cnt += mp[target];
            
            mp[sum]++;
        }

        return cnt;
    }
};