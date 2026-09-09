/*
    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    If target is not found in the array, return [-1, -1].
    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstOccu(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        int m = s+(e-s)/2;
        int ans=-1;

        while(s<=e) {
            if(arr[m] == target) {
                ans = m;
                e = m - 1;
            }
            else if(target > arr[m]) 
                s = m+1;
            else if(target < arr[m]) 
                e = m-1;

            m = s +(e-s)/2;
        }
        return ans;
    }

    int lastOccu(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        int m = (e-s)/2;
        int ans;

        while(s<=e) {
            if(arr[m] == target) {
                ans = m;
                s = m + 1;
            }
            else if(target > arr[m]) 
                s = m+1;
            else if(target < arr[m]) 
                e = m-1;

            m = s+(e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int f = firstOccu(nums,target);
        int l = lastOccu(nums, target);
        
        return {f,l};
    }
};