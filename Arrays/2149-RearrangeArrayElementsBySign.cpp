/*
    You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
    You should rearrange the elements of nums such that the modified array follows the given conditions:
    Every consecutive pair of integers have opposite signs.
    For all integers with the same sign, the order in which they were present in nums is preserved.
    The rearranged array begins with a positive integer.
    Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

    Example 1:
    Input: nums = [3,1,-2,-5,2,-4]
    Output: [3,-2,1,-5,2,-4]
    Explanation:
    The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
    The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
    Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;

        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0)
                pos.push_back(nums[i]);
            if(nums[i]<0)
                neg.push_back(nums[i]);
        }

        int i=0;
        int j=0;

        while(i<pos.size() && j<neg.size()) {
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }

        return ans;
    }
};