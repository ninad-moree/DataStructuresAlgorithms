/*
    Given a binary array nums, you should delete one element from it. Return the size of the longest non-empty subarray containing only 1's in the 
    resulting array. Return 0 if there is no such subarray.

    Example 1:
    Input: nums = [1,1,0,1]
    Output: 3
    Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int zero = 0;

        while(j < nums.size()) {
            if(nums[j] == 0)
                zero++;

            while(zero > 1) {
                if(nums[i] == 0)
                    zero--;
                i++;
            }

            ans = max(ans, j - i);

            j++;
        }

        return ans;
    }
};