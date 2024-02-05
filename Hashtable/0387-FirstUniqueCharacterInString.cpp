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
        unordered_map<char, pair<int,int>> mp;

        for(int i=0; i<s.size(); i++) {
            mp[s[i]].first = i;
            mp[s[i]].second++;
        }

        int ans = INT_MAX;

        for(auto i : mp) {
            int idx = i.second.first;
            int freq = i.second.second;

            if(freq == 1) 
                ans = min(ans, idx);
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};