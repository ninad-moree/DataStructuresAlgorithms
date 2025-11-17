/*
    Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

    Example 1:
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool ans = true;
        int prev = -1;
        int curr = -1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                if(curr != -1) {
                    prev = curr;
                    curr = i;
                    if(curr - prev - 1 < k) {
                        ans = false;
                        break;
                    }
                } else 
                    prev = curr = i;
            }
        }

        return ans;
    }
};