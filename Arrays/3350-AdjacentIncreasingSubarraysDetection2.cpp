/*
    Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are 
    strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where: Both subarrays nums[a..a + k - 1] and 
    nums[b..b + k - 1] are strictly increasing. The subarrays must be adjacent, meaning b = a + k. Return the maximum possible value of k. A subarray is a contiguous non-empty 
    sequence of elements within an array.

    Example 1:
    Input: nums = [2,5,7,8,9,2,3,4,3,1]
    Output: 3
    Explanation: The subarray starting at index 2 is [7, 8, 9], which is strictly increasing. The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
    These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cnt = 1;
        int prevCnt = 0;
        int ans = 0;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1])
                cnt++;
            else {
                prevCnt = cnt;
                cnt = 1;
            }

            ans = max(ans, min(prevCnt, cnt));
            ans = max(ans, cnt/2);
        }

        return ans;
    }
};