/*
    You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
    The length of the subarray is k, and All the elements of the subarray are distinct. Return the maximum subarray sum of all the subarrays that meet 
    the conditions. If no subarray meets the conditions, return 0. A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [1,5,4,2,9,9,9], k = 3
    Output: 15
    Explanation: The subarrays of nums with length 3 are:
    - [1,5,4] which meets the requirements and has a sum of 10.
    - [5,4,2] which meets the requirements and has a sum of 11.
    - [4,2,9] which meets the requirements and has a sum of 15.
    - [2,9,9] which does not meet the requirements because the element 9 is repeated.
    - [9,9,9] which does not meet the requirements because the element 9 is repeated.
    We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0;
        long long curr = 0; 
        unordered_map<int, int> mp;

        for(int i=0; i<k; i++) {
            mp[nums[i]]++;
            curr += nums[i];
        }

        if(mp.size() == k)
            maxi = curr;

        for(int i=k; i<nums.size(); i++) {
            int n1 = nums[i-k];
            int n2 = nums[i];
            
            mp[n1]--;
            if(mp[n1] == 0)
                mp.erase(n1);

            mp[n2]++;

            curr = curr - n1 + n2;

            if(mp.size() == k)
                maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};