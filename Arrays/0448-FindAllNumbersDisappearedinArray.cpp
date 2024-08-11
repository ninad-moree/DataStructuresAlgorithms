/*
    Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear 
    in nums.

    Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        vector<int> freq(nums.size()+1, 0);

        for(int i=0; i<nums.size(); i++) 
            freq[nums[i]]++;

        for(int i=1; i<freq.size(); i++) {
            if(freq[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};