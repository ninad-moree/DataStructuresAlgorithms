/*
    You are given a 0-indexed array of integers nums.
    A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of 
    nums[0] is sequential.
    Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

    Example 1:
    Input: nums = [1,2,3,2,5]
    Output: 6
    Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing 
    integer greater than or equal to the sum of the longest sequential prefix
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]-nums[i-1] == 1)
                prefixSum += nums[i];
            if(nums[i]-nums[i-1] != 1)
                break;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = -1;
        int idx = -1;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == prefixSum)
                idx = i;
        }
        
        if(idx == -1)
            return prefixSum;
        
        for (int i = idx; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] > 1) {
                ans = nums[i] + 1;
                break;
            }
        }

        return (ans == -1) ? nums.back() + 1 : ans;
    }
};