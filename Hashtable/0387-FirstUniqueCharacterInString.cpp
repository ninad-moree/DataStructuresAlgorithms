/*
    Given a string s, find the first non-repeating character in it and return its index. 
    If it does not exist, return -1.

    Example 1:
    Input: s = "leetcode"
    Output: 0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;

        for(auto i : s)
            mp[i]++;

        for(int i=0; i<s.size(); i++) {
            int freq = mp[s[i]];

            if(freq == 1)
                return i;
        }

        return -1;
    }
};