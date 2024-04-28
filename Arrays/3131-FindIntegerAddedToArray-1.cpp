/*
    You are given two arrays of equal length, nums1 and nums2. Each element in nums1 has been increased (or decreased in the case of negative) 
    by an integer, represented by the variable x. As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain 
    the same integers with the same frequencies. Return the integer x.

    Example 1:
    Input: nums1 = [2,6,4], nums2 = [9,7,5]
    Output: 3
    Explanation:
    The integer added to each element of nums1 is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int diff = nums2[0] - nums1[0];
        for (int i = 1; i < nums1.size(); ++i) 
            diff = min(diff, nums2[i] - nums1[i]);

        return diff;
    }
};