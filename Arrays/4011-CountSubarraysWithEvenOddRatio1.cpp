/*
    You are given an integer array nums and two integers a and b. For a subarray, let: x be the number of even elements. y be the number of odd elements.
    The ratio of even to odd elements in a subarray is defined as x / y, where ratios are compared by their exact rational values.
    A subarray is considered valid if: y > 0, and x / y <= a / b. Return the number of valid subarrays in nums.

    Example 1:
    Input: nums = [1,2,1,2], a = 3, b = 2
    Output: 7
    Explanation: The number of valid subarrays is 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            int even = 0;
            int odd = 0;

            for(int j=i; j<n; j++) {
                if(nums[j] % 2 == 0)
                    even++;
                else
                    odd++;

                if(odd > 0) {
                    if(even * b <= odd * a)
                        ans++;
                }
            }
        }

        return ans;
    }
};