/*
    A swap is defined as taking two distinct positions in an array and swapping the values in them. A circular array is defined as an array where we 
    consider the first element and the last element to be adjacent. Given a binary circular array nums, return the minimum number of swaps required to 
    group all 1's present in the array together at any location.

    Example 1:
    Input: nums = [0,1,0,1,1,0,0]
    Output: 1
    Explanation: Here are a few of the ways to group all the 1's together:
    [0,0,1,1,1,0,0] using 1 swap.
    [0,1,1,1,0,0,0] using 1 swap.
    [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
    There is no way to group all 1's together with 0 swaps.
    Thus, the minimum number of swaps required is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> arr = nums;

        for(auto i : nums)
            arr.push_back(i);

        int ones = 0;

        for(auto i : nums) {
            if(i == 1)
                ones++;
        }

        int zeros = 0;
        for(int i=0; i<ones; i++) {
            if(arr[i] == 0)
                zeros++;
        }

        int ans = zeros;

        for(int i=ones; i<arr.size(); i++) {
            if(arr[i-ones] == 0 && arr[i] == 1)
                zeros--;
            if(arr[i-ones] == 1 && arr[i] == 0)
                zeros++;
            ans = min(ans, zeros);
        }

        return ans;
    }
};