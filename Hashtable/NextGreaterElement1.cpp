/*
    The next greater element of some element x in an array is the first greater 
    element that is to the right of x in the same array.
    You are given two distinct 0-indexed integer arrays nums1 and nums2, where
    nums1 is a subset of nums2.
    For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
    and determine the next greater element of nums2[j] in nums2. If there is no next 
    greater element, then the answer for this query is -1.
    Return an array ans of length nums1.length such that ans[i] is the next greater 
    element as described above.

    Example 1:

    Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]
    Explanation: The next greater element for each value of nums1 is as follows:
    - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
    - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
    - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        unordered_map<int, int> mp;

        for (int i = 0; i < nums2.size(); ++i) {
            mp[nums2[i]] = i;
        }

        for (int num : nums1) {
            int idx = mp[num];
            int greater = -1;

            for (int j = idx + 1; j < nums2.size(); ++j) {
                if (nums2[j] > num) {
                    greater = nums2[j];
                    break;
                }
            }
            ans.push_back(greater);
        }

        return ans;
    }
};