/*
    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.

    Example 1:
    Input: nums = [3,2,3]
    Output: 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int majorityElement(int a[], int size) {
        int candidate = -1;
        int count = 0;      
        int n = size;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = a[i];
                count = 1;
            } else if (a[i] == candidate)
                count++; 
            else
                count--; 
        }
    
        count = 0; 
        for (int i = 0; i < n; i++) {
            if (a[i] == candidate)
                count++;
        }
    
        if (count > n / 2)
            return candidate;
    
        return -1;
    }
    
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n/2];

        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++) 
            mp[nums[i]]++;
        
        int n = nums.size() / 2;

        for(auto i : mp) {
            if(i.second > n)
                return i.first;
        }

        return -1;
    }
};