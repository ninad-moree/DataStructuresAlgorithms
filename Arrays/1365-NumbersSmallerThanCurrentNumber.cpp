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
        int n = nums.size();
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && nums[i] > nums[j])
                    ans[i]++;
            }
        }

        return ans;
    }
};