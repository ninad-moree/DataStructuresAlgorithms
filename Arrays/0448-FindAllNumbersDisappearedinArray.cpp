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
        int n = nums.size();
        vector<int> hash(n+1);

        for(int i=0; i<n; i++) 
            hash[nums[i]]++;
        
        vector<int> ans;
        for(int i=1; i<n+1; i++) {
            if(hash[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};