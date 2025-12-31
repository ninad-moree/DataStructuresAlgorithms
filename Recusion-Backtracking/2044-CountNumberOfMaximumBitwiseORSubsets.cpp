/*
    Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the 
    maximum bitwise OR. An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are
    considered different if the indices of the elements chosen are different. The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR 
    a[a.length - 1] (0-indexed).

    Example 1:
    Input: nums = [3,1]
    Output: 2
    Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:- [3], [3,1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int index, int currOr, int maxOr, int& cnt) {
        if(index == nums.size())
            return;

        int newOr = currOr | nums[index];
        if(newOr == maxOr)
            cnt++;
        
        solve(nums, index+1, newOr, maxOr, cnt);
        solve(nums, index+1, currOr, maxOr, cnt);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        for(auto i : nums)
            maxOr |= i;

        int cnt = 0;
        solve(nums, 0, 0, maxOr, cnt);

        return cnt;
    }
};