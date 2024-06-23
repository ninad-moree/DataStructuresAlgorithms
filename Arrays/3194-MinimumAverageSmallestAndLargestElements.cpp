/*
    You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
    You repeat the following procedure n / 2 times: Remove the smallest element, minElement, and the largest element maxElement, from nums.
    Add (minElement + maxElement) / 2 to averages. Return the minimum element in averages.

    Example 1:
    Input: nums = [7,8,3,4,15,13,4,1]
    Output: 5.5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> avgs;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()/2; i++) {
            double n = (nums[i] + nums[nums.size()-i-1])/2.0;
            avgs.push_back(n);
        }

        sort(avgs.begin(), avgs.end());

        return avgs[0];
    }
};