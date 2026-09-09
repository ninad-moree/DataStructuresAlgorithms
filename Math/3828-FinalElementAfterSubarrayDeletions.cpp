/*
    You are given an integer array nums. Two players, Alice and Bob, play a game in turns, with Alice playing first. In each turn, the current player chooses any subarray 
    nums[l..r] such that r - l + 1 < m, where m is the current length of the array. The selected subarray is removed, and the remaining elements are concatenated to form the 
    new array. The game continues until only one element remains. Alice aims to maximize the final element, while Bob aims to minimize it. Assuming both play optimally, return 
    the value of the final remaining element.

    Example 1:
    Input: nums = [1,5,2]
    Output: 2
    Explanation: One valid optimal strategy: Alice removes [1], array becomes [5, 2]. Bob removes [5], array becomes [2]​​​​​​​. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0], nums[nums.size()-1]);
    }
};