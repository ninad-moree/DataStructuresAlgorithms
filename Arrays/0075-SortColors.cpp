/*
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
    objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int c = nums.size()-1;

        while(b<=c) {
            if(nums[b] == 0) {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            else if(nums[b] == 1) 
                b++;
            else {
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};