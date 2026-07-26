/*
    Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

    Example 1:
    Input: nums = [1,2,3]
    Output: 6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];

            if(n > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = n;
            } else if(n > secondMax) {
                thirdMax = secondMax;
                secondMax = n;
            } else if(n > thirdMax) 
                thirdMax = n;

            if(n < firstMin) {
                secondMin = firstMin;
                firstMin = n;
            } else if(n < secondMin)
                secondMin = n;
        }

        int p1 = firstMax * secondMax * thirdMax;
        int p2 = firstMax * firstMin * secondMin;

        return max(p1, p2);
    }
};