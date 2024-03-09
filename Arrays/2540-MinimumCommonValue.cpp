/*
    Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays.
    If there is no common integer amongst nums1 and nums2, return -1.
    Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

    Example 1:
    Input: nums1 = [1,2,3], nums2 = [2,4]
    Output: 2
    Explanation: The smallest element common to both arrays is 2, so we return 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;

        int ans = -1;

        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] == nums2[j]) {
                ans = nums1[i];
                break;
            }
            else if(nums1[i] > nums2[j])
                j++;
            else if(nums1[i] < nums2[j])
                i++;
        }

        return ans;
    }
};