/*
    You are given a string s consisting of lowercase English letters. Return an integer denoting the maximum number of substrings you can split s into such that each substring 
    starts with a distinct character (i.e., no two substrings start with the same character).

    Example 1:
    Input: s = "abab"
    Output: 2
    Explanation: Split "abab" into "a" and "bab". Each substring starts with a distinct character i.e 'a' and 'b'. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char, int> mp;

        for(auto i : s)
            mp[i]++;

        return mp.size();
    }
};