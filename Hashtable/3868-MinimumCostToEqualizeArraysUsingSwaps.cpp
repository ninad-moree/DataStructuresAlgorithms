/*
    You are given two integer arrays nums1 and nums2 of size n. You can perform the following two operations any number of times on these two arrays: Swap within the same array:
    Choose two indices i and j. Then, choose either to swap nums1[i] and nums1[j], or nums2[i] and nums2[j]. This operation is free of charge. Swap between two arrays: Choose 
    an index i. Then, swap nums1[i] and nums2[i]. This operation incurs a cost of 1. Return an integer denoting the minimum cost to make nums1 and nums2 identical. If this is 
    not possible, return -1.

    Example 1:
    Input: nums1 = [10,20], nums2 = [20,10]
    Output: 0
    Explanation: Swap nums2[0] = 20 and nums2[1] = 10. nums2 becomes [10, 20]. This operation is free of charge. nums1 and nums2 are now identical. The cost is 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            mp[nums1[i]]++;
            mp[nums2[i]]--;
        }

        int ans = 0;

        for(auto i : mp) {
            int num = i.first;
            int freq = i.second;

            if(freq % 2 != 0)
                return -1;

            if(freq > 0)
                ans += (freq / 2);
        }

        return ans;
    }
};