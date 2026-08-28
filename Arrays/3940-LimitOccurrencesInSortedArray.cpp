/*
    You are given a sorted integer array nums and an integer k. Return an array such that each distinct element appears at most k times, while preserving the relative order of
    the elements in nums. Note: If a distinct element appears at least k times, then it must appear exactly k times in the resulting array.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,1,2,2,3]
    Explanation: Each element can appear at most 2 times. The element 1 appears 3 times, so only 2 occurrences are kept.
    The element 2 appears 2 times, so both occurrences are kept. The element 3 appears 1 time, so it is kept. Thus, the resulting array is [1, 1, 2, 2, 3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        
        int prev = nums[0];
        ans.push_back(prev);
        int cnt = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == prev) {
                cnt++;
                prev = nums[i];
                if(cnt <= k)
                    ans.push_back(nums[i]);
            } else {
                prev = nums[i];
                cnt = 1;
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};