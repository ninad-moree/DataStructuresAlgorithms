/*
    You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters. While there is a '*', do the 
    following operation: Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can 
    delete any of them. Return the lexicographically smallest resulting string after removing all '*' characters.

    Example 1:
    Input: s = "aaba*"
    Output: "aab"
    Explanation: We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        unordered_map<int, bool> mp;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') {
                mp[-pq.top().second] = true;
                pq.pop();
            } else
                pq.push({s[i], -i});
        }

        string ans = "";

        for(int i=0; i<s.size(); i++) {
            if(mp.count(i) || s[i] == '*')
                continue;
            ans += s[i];
        }

        return ans;
    }
};