/*
    The frequency of an element is the number of times it occurs in an array.
    You are given an integer array nums and an integer k. In one operation, 
    you can choose an index of nums and increment the element at that index by 1.
    Return the maximum possible frequency of an element after performing at most 
    k operations.

    Example 1:
    Input: nums = [1,2,4], k = 5
    Output: 3
    Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
    4 has a frequency of 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxFreq = 1, i = 0, j;
        long long sum = 0;

        for (j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while ((long long)nums[j] * (j - i + 1) > sum + k) {
                sum -= nums[i];
                ++i;
            }
            maxFreq = max(maxFreq, j - i + 1);
        }

        return maxFreq;
    }
};