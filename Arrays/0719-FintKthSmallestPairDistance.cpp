/*
    The distance of a pair of integers a and b is defined as the absolute difference between a and b.
    Given an integer array nums and an integer k, return the kth smallest distance among all the pairs
     nums[i] and nums[j] where 0 <= i < j < nums.length.

    Example 1:
    Input: nums = [1,3,1], k = 1
    Output: 0
    Explanation: Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > mid)
                left++;
            count += right - left;
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums[nums.size() - 1] - nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};