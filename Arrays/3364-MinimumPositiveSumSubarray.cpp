/*
    You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is 
    greater than 0. Return the minimum sum of such a subarray. If no such subarray exists, return -1. A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [3, -2, 1, 4], l = 2, r = 3
    Output: 1
    Explanation: The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
    [3, -2] with a sum of 1, [1, 4] with a sum of 5, [3, -2, 1] with a sum of 2, [-2, 1, 4] with a sum of 3
    Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefix(n+1);
        for(int i=0; i<n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        multiset<long long> window;
        long long ans = LLONG_MAX;

        for(int right=l; right<=n; right++) {
            window.insert(prefix[right - l]);

            if(right - r - 1 >= 0)
                window.erase(window.find(prefix[right - r - 1]));

            auto it = window.lower_bound(prefix[right]); // largest prefix[i] strictly lesser than prefix[right]

            if(it != window.begin()) {
                --it;
                ans = min(ans, prefix[right] - *it);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};