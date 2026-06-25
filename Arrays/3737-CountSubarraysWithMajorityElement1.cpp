/*
    You are given an integer array nums and an integer target. Return the number of subarrays of nums in which target is the majority element. The majority element of a subarray
    is the element that appears strictly more than half of the times in that subarray.

    Example 1:
    Input: nums = [1,2,2,3], target = 2
    Output: 5
    Explanation: Valid subarrays with target = 2 as the majority element:
    nums[1..1] = [2], nums[2..2] = [2], nums[1..2] = [2,2], nums[0..2] = [1,2,2], nums[1..3] = [2,2,3]
    So there are 5 such subarrays.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            
            for (int j = i; j < n; j++) {
                if (nums[j] == target) 
                    cnt++;

                int len = j - i + 1;
                if (2 * cnt > len)
                    ans++;
            }
        }

        return ans;
    }
};