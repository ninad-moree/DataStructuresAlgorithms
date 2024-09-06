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
        if(nums.size() == 0)
            return 0;
            
        sort(nums.begin(), nums.end());
        
        int len = 1;
        int currLen = 1;
        int num = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == num + 1) {
                num = nums[i];
                currLen++;
                len = max(len, currLen);
            } else if (nums[i] == num){
                continue;
            } else {
                currLen = 1;
                num = nums[i];
            }
        }

        return len;
    }
};