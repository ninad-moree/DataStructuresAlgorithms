/*
    Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by 
    p. It is not allowed to remove the whole array. Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
    A subarray is defined as a contiguous block of elements in the array.

    Example 1:
    Input: nums = [3,1,4,2], p = 6
    Output: 1
    Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining 
    elements is 6, which is divisible by 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto i : nums)
            sum += i;

        if(sum % p == 0)
            return 0;

        sum = sum % p;
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefixSum = 0;
        int ans = nums.size();

        for(int i=0; i<nums.size(); i++) {
            prefixSum = (prefixSum + nums[i]) % p;

            int diff = (prefixSum - sum + p) % p;

            if(mp.find(diff) != mp.end()) 
                ans = min(ans, i - mp[diff]);

            mp[prefixSum] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};