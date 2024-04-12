/*
    Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.

    Example 1:
    Input: nums1 = [4,1,3], nums2 = [5,7]
    Output: 15
    Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest 
    number we can have.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_map<int, int> mp;
        for(int i=0; i<nums1.size(); i++) {
            mp[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++) {
            if(mp.find(nums2[i]) != mp.end()) {
                return nums2[i];
            }
        }

        int a = nums1[0];
        int b = nums2[0];

        if(a>b) 
            return a+b*10;
        else
            return b+a*10;
    }
};