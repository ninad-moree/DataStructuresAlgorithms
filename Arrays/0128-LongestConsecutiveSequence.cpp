/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 1;
        int curr = 1;

        if(nums.size() == 0)
            return 0;

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1])
                continue;
            else if(nums[i] + 1 == nums[i+1]) {
                curr++;
                ans = max(ans, curr);
            } else
                curr = 1;
        }

        return ans;
    }
};