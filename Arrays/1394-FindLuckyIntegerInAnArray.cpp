/*
    Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
    Return the largest lucky integer in the array. If there is no lucky integer return -1.

    Example 1:
    Input: arr = [2,2,3,4]
    Output: 2
    Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(auto i : arr)
            mp[i]++;

        int ans = -1;

        for(auto i : mp) {
            if(i.first == i.second)
                ans = max(ans, i.first);
        }

        return ans;
    }
};