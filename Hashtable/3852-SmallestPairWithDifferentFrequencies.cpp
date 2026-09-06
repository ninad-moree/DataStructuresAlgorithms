/*
    You are given an integer array nums. Consider all pairs of distinct values x and y from nums such that: x < y x and y have different frequencies in nums.
    Among all such pairs: Choose the pair with the smallest possible value of x. If multiple pairs have the same x, choose the one with the smallest possible value of y.
    Return an integer array [x, y]. If no valid pair exists, return [-1, -1].

    Example 1:
    Input: nums = [1,1,2,2,3,4]
    Output: [1,3]
    Explanation: The smallest value is 1 with a frequency of 2, and the smallest value greater than 1 that has a different frequency from 1 is 3 with a frequency of 1. Thus, the
    answer is [1, 3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        int x = *min_element(nums.begin(), nums.end());

        int y = INT_MAX;

        for (auto i : freq) {
            int val = i.first;
            int cnt = i.second;

            if (val > x && cnt != freq[x]) 
                y = min(y, val);
        }

        if (y == INT_MAX)
            return {-1, -1};

        return {x, y};
    }
};