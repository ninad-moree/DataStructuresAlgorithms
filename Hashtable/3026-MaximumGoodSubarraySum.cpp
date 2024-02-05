/*
    You are given an array nums of length n and a positive integer k.
    A subarray of nums is called good if the absolute difference between its first and last element 
    is exactly k, in other words, the subarray nums[i..j] is good if |nums[i] - nums[j]| == k.
    Return the maximum sum of a good subarray of nums. If there are no good subarrays, return 0.

    Example 1:
    Input: nums = [1,2,3,4,5,6], k = 1
    Output: 11
    Explanation: The absolute difference between the first and last element must be 1 for a good subarray. 
    All the good subarrays are: [1,2], [2,3], [3,4], [4,5], and [5,6]. The maximum subarray sum is 11 for 
    the subarray [5,6].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = LONG_MIN;

        vector<long long> prefixSum(nums.size(), nums[0]);
        for(int i=1; i<nums.size(); i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        map<int, vector<int>> idxMap;
        for(int i=0; i<nums.size(); i++)
            idxMap[nums[i]].push_back(i);

        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            int v1 = val - k;
            int v2 = val + k;

            if(idxMap.find(v1) != idxMap.end()) {
                for(auto j : idxMap[v1]) {
                    if(i<j)
                        ans = max(ans, prefixSum[j] - prefixSum[i] + nums[i]);
                    else 
                        ans = max(ans, prefixSum[i] - prefixSum[j] + nums[j]);
                }
            }

            if(idxMap.find(v2) != idxMap.end()) {
                for(auto j : idxMap[v1]) {
                    if(i<j)
                        ans = max(ans, prefixSum[j] - prefixSum[i] + nums[i]);
                    else 
                        ans = max(ans, prefixSum[i] - prefixSum[j] + nums[j]);
                }
            }
        
        }
        if(ans == LONG_MIN)
            return 0;

        return ans;  
    }
};