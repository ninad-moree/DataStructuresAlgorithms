/*
    Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal. In one move, you can increment n - 1 elements of the 
    array by 1.

    Example 1:
    Input: nums = [1,2,3]
    Output: 3
    Explanation: Only three moves are needed (remember each move increments two elements): [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;

        for(auto i : nums) {
            sum += i;
            mini = min(mini, i);
        }

        return sum - (n * mini);
    }
};