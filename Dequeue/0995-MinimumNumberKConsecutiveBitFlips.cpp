/*
    You are given a binary array nums and an integer k. A k-bit flip is choosing a subarray of length k from nums and simultaneously changing 
    every 0 in the subarray to 1, and every 1 in the subarray to 0. Return the minimum number of k-bit flips required so that there is no 0 in 
    the array. If it is not possible, return -1.

    Example 1:
    Input: nums = [0,1,0], k = 1
    Output: 2
    Explanation: Flip nums[0], then flip nums[2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip_count = 0;
        int result = 0;
        deque<int> flips;

        for (int i = 0; i < n; ++i) {
            if (!flips.empty() && flips.front() == i) {
                flips.pop_front();
                flip_count--;
            }
            
            if ((nums[i] + flip_count) % 2 == 0) {
                if (i + k > n) 
                    return -1; 
                flips.push_back(i + k);
                flip_count++;
                result++;
            }
        }
        
        return result;
    }
};