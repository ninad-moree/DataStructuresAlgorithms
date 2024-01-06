/*
    Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
    That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
    Return the answer in an array.
    
    Example 1:
    Input: nums = [8,1,2,2,3]
    Output: [4,0,1,1,3]
    Explanation: 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++) {
            int small = 0;
            for(int j=0;j<nums.size();j++) {
                if(nums[j] < nums[i])
                    small++;
            }
            ans.push_back(small);
        }

        return ans;
    }
};