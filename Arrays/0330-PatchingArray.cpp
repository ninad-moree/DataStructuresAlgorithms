/*
    Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be 
    formed by the sum of some elements in the array. Return the minimum number of patches required.

    Example 1:
    Input: nums = [1,3], n = 6
    Output: 1
    Explanation:
    Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
    Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
    Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int ans = 0;
        int i = 0;

        while(sum < n) {
            if(i < nums.size() && nums[i] <= sum+1)
                sum += nums[i++];
            else {
                ans++;
                sum = sum*2+1;
            }
        }

        return ans;
    }
};