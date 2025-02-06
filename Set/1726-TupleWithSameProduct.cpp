/*
    Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are 
    elements of nums, and a != b != c != d.

    Example 1:
    Input: nums = [2,3,4,6]
    Output: 8
    Explanation: There are 8 valid tuples:
    (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
    (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            for(int j=nums.size()-1; j>=i+1; j--) {
                int prod = nums[i] * nums[j];

                unordered_set<int> s;

                for(int k=i+1; k<j; k++) {
                    if(prod % nums[k] == 0) {
                        int val = prod / nums[k];

                        if(s.find(val) != s.end()) 
                            ans += 8;

                        s.insert(nums[k]);
                    }
                }
            }
        }

        return ans;
    }
};