/*
    Ninja and his friend are playing a game of subarrays. They have an array ‘NUMS’ of length ‘N’. Ninja’s friend gives him an arbitrary 
    integer ‘K’ and asks him to find the length of the longest subarray in which the sum of elements is equal to ‘K’.
    Ninjas asks for your help to win this game. Find the length of the longest subarray in which the sum of elements is equal to ‘K’.
    If there is no subarray whose sum is ‘K’ then you should return 0.

    Example:
    Input: ‘N’ = 5,  ‘K’ = 4, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]
    Output: 4
    There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.
*/

#include<bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    unordered_map<int, int> mp; 
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i]; 

        if (sum == k)
            maxLen = i + 1;

        if (mp.find(sum - k) != mp.end())
            maxLen = max(maxLen, i - mp[sum - k]);

        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return maxLen;
}