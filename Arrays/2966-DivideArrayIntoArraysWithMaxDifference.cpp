/*
    You are given an integer array nums of size n and a positive integer k.
    Divide the array into one or more arrays of size 3 satisfying the following conditions:
    Each element of nums should be in exactly one array.
    The difference between any two elements in one array is less than or equal to k.
    Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, 
    return an empty array. And if there are multiple answers, return any of them.

    Example 1:
    Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
    Output: [[1,1,3],[3,4,5],[7,8,9]]
    Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
    The difference between any two elements in each array is less than or equal to 2.
    Note that the order of elements is not important.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<=nums.size()-3;i=i+3) {
            vector<int> res;
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(abs(a-b)<=k && abs(a-c)<=k && abs(b-c)<=k) {
                res.push_back(a);
                res.push_back(b);
                res.push_back(c);
                ans.push_back(res);
            }
            else 
                return {};
        }

        return ans;
    }
};