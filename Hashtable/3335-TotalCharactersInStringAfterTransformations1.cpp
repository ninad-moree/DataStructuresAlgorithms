/*
    You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is 
    replaced according to the following rules:
    If the character is 'z', replace it with the string "ab".
    Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
    Return the length of the resulting string after exactly t transformations.
    Since the answer may be very large, return it modulo 109 + 7.

    Example 1:
    Input: s = "abcyy", t = 2
    Output: 7
    Explanation:
    First Transformation (t = 1):
    'a' becomes 'b'
    'b' becomes 'c'
    'c' becomes 'd'
    'y' becomes 'z'
    'y' becomes 'z'
    String after the first transformation: "bcdzz"
    Second Transformation (t = 2):
    'b' becomes 'c'
    'c' becomes 'd'
    'd' becomes 'e'
    'z' becomes "ab"
    'z' becomes "ab"
    String after the second transformation: "cdeabab"
    Final Length of the string: The string is "cdeabab", which has 7 characters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;

        vector<int> freq(26, 0);
        for(auto i : s)
            freq[i - 'a']++;

        for(int i=0; i<t; i++) {
            vector<int> mp(26, 0);
            mp[0] = freq[25];
            mp[1] = (freq[25] + freq[0])%mod;

            for(int i=2; i<26; i++) 
                mp[i] = freq[i-1];

            freq = move(mp);
        }

        int ans = 0;
        for(int i=0; i<26; i++)
            ans = (ans + freq[i])%mod;
        
        return ans;
    }
};