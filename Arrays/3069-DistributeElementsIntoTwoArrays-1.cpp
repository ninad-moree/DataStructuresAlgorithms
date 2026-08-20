/*
    You are given a 1-indexed array of distinct integers nums of length n. You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. 
    In the first operation, append nums[1]  to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:
    If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2. The array result is formed by concatenating 
    the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then  result = [1,2,3,4,5,6]. Return the array result.

    Example 1:
    Input: nums = [2,1,3]
    Output: [2,3,1]
    Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1]. In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (2 > 1),
    append nums[3] to arr1. After 3 operations, arr1 = [2,3] and arr2 = [1]. Hence, the array result formed by concatenation is [2,3,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> a1, a2;

        a1.push_back(nums[0]);
        a2.push_back(nums[1]);

        for(int i=2; i<n; i++) {
            if(a1.back() > a2.back())
                a1.push_back(nums[i]);
            else
                a2.push_back(nums[i]);
        }

        int idx = 0;
        for(int i=0; i<a1.size(); i++) {
            ans[idx] = a1[i];
            idx++;
        }

        for(int i=0; i<a2.size(); i++) {
            ans[idx] = a2[i];
            idx++;
        }

        return ans;
    }
};