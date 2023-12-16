/*
    Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

    Input: nums1 = [1,2,3], nums2 = [2,4,6]
    Output: [[1,3],[4,6]]
    Explanation:
    For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
    For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiff(const vector<int>& a, const vector<int>& b) {
        unordered_map<int, int> freq;
        unordered_set<int> seen;
        vector<int> diff;

        for (int num : b) {
            freq[num]++;
        }

        for (int num : a) {
            if (freq.find(num) == freq.end() && seen.find(num) == seen.end()) {
                diff.push_back(num);
                seen.insert(num); 
            }
        }

        return diff;
    }

     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;

        vector<int> diff1 = findDiff(nums1, nums2);
        vector<int> diff2 = findDiff(nums2, nums1);

        ans.push_back(diff1);
        ans.push_back(diff2);

        return ans;
    }
};