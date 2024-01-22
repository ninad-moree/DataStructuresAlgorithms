/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        int i=0;
        int j=0;

        vector<int> merge;

        while(i<l1 && j<l2) {
            if(nums1[i]<nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            }
            else {
                merge.push_back(nums2[j]);
                j++;
            }
        }

        while(i<l1) {
            merge.push_back(nums1[i]);
            i++;
        }

        while(j<l2) {
            merge.push_back(nums2[j]);
            j++;
        }

        int l = merge.size();
        double a;

        if(l%2==1)  a = merge[l/2];
        else a = (merge[l/2] + merge[l/2 - 1])/2.0;

        return a;
    }
};