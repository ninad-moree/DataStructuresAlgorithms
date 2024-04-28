/*
    You are given two integer arrays nums1 and nums2. From nums1 two elements have been removed, and all other elements have been increased 
    (or decreased in the case of negative) by an integer, represented by the variable x. As a result, nums1 becomes equal to nums2. Two arrays 
    are considered equal when they contain the same integers with the same frequencies. Return the minimum possible integer x that achieves this 
    equivalence.

    Example 1:
    Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]
    Output: -2
    Explanation:
    After removing elements at indices [0,4] and adding -2, nums1 becomes [18,14,10].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSame(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j = 0;
        int steps = 2;
        
        while(i<nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                i++;
                j++;
            } else {
                i++;
                steps--;
                if(steps < 0)
                    return false;
            }
        }
    
        return j == nums2.size() && (i-j) <= 2;
    }
    
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {  
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        unordered_map<int, int> mp;
        
        int mini = INT_MAX;
        
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                int diff = nums2[j] - nums1[i];
                mp[diff]++;
            }
        }
        
        for(auto& m : mp) {
            int diff = m.first;
            int cnt = m.second;
            vector<int> curr(nums1.size());
            for(int i=0; i<nums1.size(); i++) {
                curr[i] = nums1[i] + diff;
            }
            
            sort(curr.begin(), curr.end());
            
            if(isSame(curr, nums2))
                mini = min(mini, diff);
        }
        
        return mini;
    }
};