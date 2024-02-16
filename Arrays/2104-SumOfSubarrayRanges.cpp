/*
    You are given an integer array nums. The range of a subarray of nums is the 
    difference between the largest and smallest element in the subarray.
    Return the sum of all subarray ranges of nums.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [1,2,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0 
    [2], range = 2 - 2 = 0
    [3], range = 3 - 3 = 0
    [1,2], range = 2 - 1 = 1
    [2,3], range = 3 - 2 = 1
    [1,2,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        stack<int> st;

        for(int i=0;i<nums.size();i++) {
            int maxi = nums[i];
            int mini = nums[i];
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j] > maxi)
                    maxi = nums[j];
                else if (nums[j] < mini)
                    mini = nums[j];
                sum += maxi - mini;
            }
        }

        return sum;
    }
};
