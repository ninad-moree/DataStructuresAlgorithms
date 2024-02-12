/*
    You are given a 0-indexed sorted array of integers nums.
    You can perform the following operation any number of times:
    Choose two indices, i and j, where i < j, such that nums[i] < nums[j].
    Then, remove the elements at indices i and j from nums. The remaining elements retain their 
    original order, and the array is re-indexed.
    Return an integer that denotes the minimum length of nums after performing the operation any number of times (including zero).
    Note that nums is sorted in non-decreasing order.

    Example 1:
    Input: nums = [1,3,4,9]
    Output: 0
    Explanation: Initially, nums = [1, 3, 4, 9].
    In the first operation, we can choose index 0 and 1 because nums[0] < nums[1] <=> 1 < 3.
    Remove indices 0 and 1, and nums becomes [4, 9].
    For the next operation, we can choose index 0 and 1 because nums[0] < nums[1] <=> 4 < 9.
    Remove indices 0 and 1, and nums becomes an empty array [].
    Hence, the minimum length achievable is 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;
        
        int maxFreq = INT_MIN;
        for(auto i : mp) 
            maxFreq = max(maxFreq, i.second);

        if(maxFreq <= nums.size() / 2) {
            if(nums.size() % 2)
                return 1;
            else
                return 0;
        }

        return 2*maxFreq - nums.size();
    }
};