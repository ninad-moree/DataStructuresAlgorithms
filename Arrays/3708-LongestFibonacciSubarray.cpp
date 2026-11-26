/*
    You are given an array of positive integers nums. A Fibonacci array is a contiguous sequence whose third and subsequent terms each equal the sum of the two preceding terms.
    Return the length of the longest Fibonacci subarray in nums. Note: Subarrays of length 1 or 2 are always Fibonacci.

    Example 1:
    Input: nums = [1,1,1,1,2,3,5,1]
    Output: 5
    Explanation: The longest Fibonacci subarray is nums[2..6] = [1, 1, 2, 3, 5]. [1, 1, 2, 3, 5] is Fibonacci because 1 + 1 = 2, 1 + 2 = 3, and 2 + 3 = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) 
            return n;

        int ans = 2;
        int curr = 2;
        int j = 2;

        while(j < nums.size()) {
            int a = nums[j-2];
            int b = nums[j-1];
            int c = nums[j];

            if(c == a + b) 
                curr++;
            else 
                curr = 2;
            
            ans = max(ans, curr);
            j++;
        }

        return ans;
    }
};