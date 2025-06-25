/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:
    Input: nums = [3,2,3]
    Output: [3]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            if(cnt1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                cnt1 = 1;
            } else if(cnt2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                cnt2 = 1;
            } else if(ele1 == nums[i])
                cnt1++;
            else if(ele2 == nums[i])
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        int f1 = 0;
        int f2 = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == ele1)
                f1++;
            else if(nums[i] == ele2)
                f2++;
        }

        vector<int> res;
        if(f1 > nums.size()/3)
            res.push_back(ele1);
        if(f2 > nums.size()/3)
            res.push_back(ele2);

        return res;
    }
};