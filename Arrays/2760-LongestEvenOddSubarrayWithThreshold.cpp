/*
    You are given a 0-indexed integer array nums and an integer threshold.
    Find the length of the longest subarray of nums starting at index l and ending at index r (0 <= l <= r < nums.length) 
    that satisfies the following conditions:
        nums[l] % 2 == 0
        For all indices i in the range [l, r - 1], nums[i] % 2 != nums[i + 1] % 2
        For all indices i in the range [l, r], nums[i] <= threshold
    Return an integer denoting the length of the longest such subarray.
    Note: A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [3,2,5,4], threshold = 5
    Output: 3
    Explanation: In this example, we can select the subarray that starts at l = 1 and ends at r = 3 => [2,5,4]. This subarray satisfies the conditions.
    Hence, the answer is the length of the subarray, 3. We can show that 3 is the maximum possible achievable length.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int len = 1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2==0 && ans==0 && nums[i]<=threshold)
                ans = 1;
            
            for(int j=i+1; j<nums.size(); j++) {
                if (nums[i] % 2 == 0 && nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= threshold && nums[i] <= threshold ) {
                    len++;
                    ans = max(ans, len);
                } else
                    break;
            }

            len = 1;
        }

        return ans;
    }
};