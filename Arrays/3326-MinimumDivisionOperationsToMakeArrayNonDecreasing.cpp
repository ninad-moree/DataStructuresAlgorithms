/*
    You are given an integer array nums. Any positive divisor of a natural number x that is strictly less than x is called a proper divisor of x. For 
    example, 2 is a proper divisor of 4, while 6 is not a proper divisor of 6. You are allowed to perform an operation any number of times on nums, 
    where in each operation you select any one element from nums and divide it by its greatest proper divisor. Return the minimum number of operations 
    required to make the array non-decreasing. If it is not possible to make the array non-decreasing using any number of operations, return -1.

    Example 1:
    Input: nums = [25,7]
    Output: 1
    Explanation: Using a single operation, 25 gets divided by 5 and nums becomes [5, 7].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;

        for(int i=nums.size()-1; i>=1; i--) {
            int curr = nums[i-1];
            int next = nums[i];

            if(curr > next) {
                int j = next;

                while(curr % j != 0)
                    j--;

                if(j != 1) {
                    nums[i-1] = j;
                    ans++;
                }
            }

            if(nums[i-1] > nums[i])
                return -1;
        }

        return ans;
    }
};