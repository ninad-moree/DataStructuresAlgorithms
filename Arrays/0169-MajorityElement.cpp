/*
    Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.

    Example 1:
    Input: nums = [3,2,3]
    Output: 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            } else if(nums[i] == ele)
                cnt++;
            else
                cnt--;
        }

        return ele;
    }
};