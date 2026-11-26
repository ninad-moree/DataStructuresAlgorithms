/*
    You are given an integer array nums and an integer k. A subarray is resilient if, for every position in it, deleting the element at that position leaves the remaining 
    elements with a sum divisible by k. For a subarray of length 1, the remaining sum is 0, which is divisible by k. Return the length of the longest resilient subarray.

    Example 1:
    Input: nums = [2,4,6,3], k = 2
    Output: 3
    Explanation: The subarray [2, 4, 6] sums to 12. Deleting 2, 4, or 6 leaves a sum of 10, 8, or 6, respectively, each of which is divisible by 2. Therefore, the answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int len = 1;

        for(int i=1; i<nums.size(); i++) {
            int rem = nums[i] % k;

            if(rem == nums[i-1] % k)
                len++;
            else
                len = 1;

            if((len - 1) * rem % k == 0)
                ans = max(ans, len);
        }

        return ans;
    }
};