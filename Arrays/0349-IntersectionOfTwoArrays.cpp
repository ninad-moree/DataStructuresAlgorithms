/*
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be 
    unique and you may return the result in any order.

    Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0;
        int j=0;

        vector<int> ans;

        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] < nums2[j])
                i++;
            else if(nums1[i] > nums2[j])
                j++;
            else {
                if(ans.size()==0)
                    ans.push_back(nums1[i]);
                if(ans[ans.size()-1] != nums1[i])
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};