/*
    You are given an integer array nums. You are allowed to delete any number of elements from nums without making it empty. After performing the 
    deletions, select a subarray of nums such that:
    All elements in the subarray are unique. The sum of the elements in the subarray is maximized.
    Return the maximum sum of such a subarray.

    Example 1:
    Input: nums = [1,2,3,4,5]
    Output: 15
    Explanation: Select the entire array without deleting any element to obtain the maximum sum.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = INT_MIN;

        for(auto i : nums) 
            maxi = max(maxi, i);

        if(maxi < 0)
            return maxi;

        unordered_set<int> st;

        for(auto i : nums)
            st.insert(i);

        int sum = 0;

        for(auto i : st) {
            if(i > 0)
                sum += i;
        }

        return sum;
            
    }
};