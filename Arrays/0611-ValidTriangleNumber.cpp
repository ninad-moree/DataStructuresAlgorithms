/*
    Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a 
    triangle.

    Example 1:
    Input: nums = [2,2,3,4]
    Output: 3
    Explanation: Valid combinations are: 
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        for(int i=nums.size()-1; i>=2; i--) {
            int left = 0;
            int right = i-1;

            while(left < right) {
                int s1 = nums[i];
                int s2 = nums[left];
                int s3 = nums[right];

                if(s2 + s3 > s1) {
                    ans += (right - left);
                    right--;
                } else
                    left++;
            }
        }

        return ans;
    }
};