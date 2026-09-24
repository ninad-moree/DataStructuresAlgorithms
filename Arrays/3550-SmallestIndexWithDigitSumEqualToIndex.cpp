/*
    You are given an integer array nums. Return the smallest index i such that the sum of the digits of nums[i] is equal to i. If no such index exists, return -1.

    Example 1:
    Input: nums = [1,3,2]
    Output: 2
    Explanation: For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int idx = -1;

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            int sum = 0;

            while(n) {
                int d = n % 10;
                n = n / 10;

                sum += d;
            }

            if(sum == i) {
                idx= i;
                break;
            }
        }

        return idx;
    }
};