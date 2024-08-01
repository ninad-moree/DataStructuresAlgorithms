/*
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the 
    array.

    Example 1:
    Input: nums = [3,0,1]
    Output: 2
    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it 
    does not appear in nums.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> freq(nums.size()+1, 0);

        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }

        int ans;

        for(int i=0; i<freq.size(); i++) {
            if(freq[i] == 0) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};