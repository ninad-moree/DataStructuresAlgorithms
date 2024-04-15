/*
    You are given a 0-indexed integer array nums. We say that an integer x is expressible from nums if there exist some integers 
    0 <= index1 < index2 < ... < indexk < nums.length for which nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, 
    an integer is expressible if it can be written as the bitwise OR of some subsequence of nums.
    Return the minimum positive non-zero integer that is not expressible from nums.

    Example 1:
    Input: nums = [2,1]
    Output: 4
    Explanation: 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is
    not expressible, we return 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int power = 1;

        if(nums[0] != 1)
            return 1;
        
        power = power*2;

        int ans = -1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < power)
                continue;
            else if(nums[i] == power) {
                power = power*2;
            }
            else if(nums[i] > power){
                ans = power;
                break;
            }
        }

        if(ans == -1)
            return power;
        
        return ans;
    }
};