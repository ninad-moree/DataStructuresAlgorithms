/*
    Given a string s consisting only of characters a, b and c.
    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

    Example 1:
    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters 
    a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        unordered_map<char, int> mp;
        int i = 0;

        for(int j=0;j<s.size();j++) {
            mp[s[j]]++;

            while(mp['a'] && mp['b'] && mp['c']) {
                mp[s[i]]--;
                i++;
            }

            cnt += i;
        }

        return cnt;
    }
};