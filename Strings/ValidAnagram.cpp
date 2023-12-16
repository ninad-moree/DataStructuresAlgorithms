/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or 
    phrase, typically using all the original letters exactly once.

    Input: s = "anagram", t = "nagaram"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;

        bool ans = true;

        for(int i=0;i<n;i++) {
            if(s[i]!=t[i])
                ans = false;
        }
        return ans;
    }
};