/*
    You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
    Return the minimum number of moves to make every value in nums unique.
    The test cases are generated so that the answer fits in a 32-bit integer.

    Example 1:
    Input: nums = [1,2,2]
    Output: 1
    Explanation: After 1 move, the array could be [1, 2, 3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  

        int ans = 0;
        int res = nums[0];  

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < res) {
                ans += res - nums[i];
                nums[i] = res;  
            }
            res = nums[i] + 1;  
        }

        return ans;
    }
};
