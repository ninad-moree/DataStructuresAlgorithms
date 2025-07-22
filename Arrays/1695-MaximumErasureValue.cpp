/*
    You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the 
    subarray is equal to the sum of its elements. Return the maximum score you can get by erasing exactly one subarray. An array b is called to be a
    subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

    Example 1:
    Input: nums = [4,2,4,5,6]
    Output: 17
    Explanation: The optimal subarray here is [2,4,5,6].
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int left = 0;
        int right = 0;
        int curr = 0;
        int maxi = 0;

        while(right < nums.size()) {
            while(st.find(nums[right]) != st.end()) {
                curr -= nums[left];
                st.erase(nums[left]);
                ++left;
            }

            curr += nums[right];
            st.insert(nums[right]);
            maxi = max(maxi, curr);

            right++;
        }

        return maxi;
    }
};