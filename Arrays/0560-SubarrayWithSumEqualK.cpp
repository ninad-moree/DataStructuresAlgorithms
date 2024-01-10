/*
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        int count = 0;
        int sum = 0;

        sumFreq[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (sumFreq.find(sum - k) != sumFreq.end()) 
                count += sumFreq[sum - k];
            
            sumFreq[sum]++;
        }

        return count;
    }
};