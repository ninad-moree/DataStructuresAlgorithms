/*
    You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
    The 2D array should contain only the elements of the array nums.
    Each row in the 2D array contains distinct integers.
    The number of rows in the 2D array should be minimal.
    Return the resulting array. If there are multiple answers, return any of them.

    Example 1:
    Input: nums = [1,3,4,1,2,3,1]
    Output: [[1,3,4,2],[1,3],[1]]
    Explanation: We can create a 2D array that contains the following rows:
    - 1,3,4,2
    - 1,3
    - 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;

        for(int i : nums)
            mp[i]++;

        int max = INT_MIN;

        for(auto i : mp) {
            if(i.second>max) 
                max = i.second;
        }

        vector<vector<int>> ans(max);

        for(auto j: mp) {
            for(int i=0;i<j.second;i++) 
                ans[i].push_back(j.first);
        }
        return ans;
    }
};