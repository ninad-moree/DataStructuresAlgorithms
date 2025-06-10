/*
    You are given a string s consisting of lowercase English letters. Your task is to find the maximum difference diff = freq(a1) - freq(a2) between 
    the frequency of characters a1 and a2 in the string such that:
    a1 has an odd frequency in the string. a2 has an even frequency in the string.
    Return this maximum difference.

    Example 1:
    Input: s = "aaaaabbc"
    Output: 3
    Explanation: The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2. The maximum difference is 5 - 2 = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for(auto i : s)
            mp[i]++;

        int maxi = 0;
        int mini = INT_MAX;

        for(auto i : mp) {
            if(i.second % 2 == 1) 
                maxi = max(maxi, i.second);
            else
                mini = min(mini, i.second);
        }

        return maxi - mini;
    }
};