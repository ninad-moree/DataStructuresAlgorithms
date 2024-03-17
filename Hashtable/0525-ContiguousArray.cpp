/*
    Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

    Example 1:
    Input: nums = [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap;
        int maxLen = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 1) ? 1 : -1;

            if (count == 0) 
                maxLen = max(maxLen, i + 1);
            else if (countMap.find(count) != countMap.end()) 
                maxLen = max(maxLen, i - countMap[count]);
            else 
                countMap[count] = i;
        }

        return maxLen;
    }
};