/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1.size() + nums2.size());

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                arr[k] = nums1[i];
                i++;
                k++;
            } else {
                arr[k] = nums2[j];
                j++;
                k++;
            }
        }

        while(i < nums1.size()) {
            arr[k] = nums1[i];
            i++;
            k++;
        }

        while(j < nums2.size()) {
            arr[k] = nums2[j];
            j++;
            k++;
        }

        double ans;

        if(arr.size() % 2 == 1) 
            ans = arr[arr.size() / 2];
        else {
            double n1 = arr[arr.size()/2 - 1];
            double n2 = arr[arr.size()/2];
            ans = (n1 + n2) / 2.0;
        }

        return ans;
    }
};