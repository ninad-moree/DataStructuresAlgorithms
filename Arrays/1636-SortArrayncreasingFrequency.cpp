/*
    Given an array of integers nums, sort the array in increasing order based on the frequency of the values. 
    If multiple values have the same frequency, sort them in decreasing order.
    Return the sorted array.

    Example 1:
    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> arr(201, 0);

        for(auto i : nums) {
            arr[i+100]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(arr[a+100] == arr[b+100])
                return a>b;
            return arr[a+100] < arr[b+100];
        });

        return nums;
    }
};