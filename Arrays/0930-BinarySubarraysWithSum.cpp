/*
    Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
    A subarray is a contiguous part of the array.

    Example 1:
    Input: nums = [1,0,1,0,1], goal = 2
    Output: 4 
    (1,0,1) (0,1,0) (0,1,0,1) (1,0,1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        int cnt = 0;
        int sum =0;

        for (j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum > goal && i < j) {
                sum -= nums[i];
                i++;
            }

            if (sum == goal) {
                int k = i;
                while (k < j && nums[k] == 0) {
                    cnt++;
                    k++;
                }
                cnt++;
            }
        }

        return cnt;
    }
};