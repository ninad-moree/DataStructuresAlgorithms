/*
    Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
    Return the minimized largest sum of the split. A subarray is a contiguous part of the array.

    Example 1:
    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArray(vector<int> nums, int maxSum) {
        int sum = 0;
        int cnt = 1;

        for(auto i : nums) {
            if(sum + i <= maxSum)
                sum += i;
            else {
                sum = i;
                cnt++;
            }
        }

        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int cnt = countArray(nums, mid);

            if(cnt > k)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};