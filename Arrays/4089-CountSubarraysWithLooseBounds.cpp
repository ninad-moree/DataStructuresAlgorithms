/*
    You are given an integer array nums and two integers minK and maxK. A loose-bound subarray is a subarray in which every element is greater than or equal to minK and less 
    than or equal to maxK. Return the number of loose-bound subarrays in nums.

    Example 1:
    Input: nums = [1,4,7,3], minK = 1, maxK = 5
    Output: 4
    Explanation: The loose-bound subarrays are [1], [4], [3], and [1, 4]. The minimum value in these subarrays is at least minK = 1 and the maximum value is at most maxK = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long ans = 0;

        while(right < n) {
            if(nums[right] >= minK && nums[right] <= maxK)
                ans += (right - left + 1);
            else
                left = right + 1;
            
            right++;
        }

        return ans;
    }
};