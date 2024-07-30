/*
    You are given a string s consisting only of characters 'a' and 'b'​​​​. You can delete any number of characters in s to make s balanced. 
    s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
    Return the minimum number of deletions needed to make s balanced.

    Example 1:
    Input: s = "aababbab"
    Output: 2
    Explanation: You can either:
    Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
    Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = INT_MAX;

        vector<int> prefixB(s.size(), 0);
        vector<int> suffixA(s.size(), 0);

        prefixB[0] = (s[0] == 'b');
        
        int cntA = 0;
        for(auto i : s) {
            if(i == 'a')
                cntA++;
        }

        suffixA[s.size()-1] = (s[s.size()-1] == 'a');

        for(int i=1; i<s.size(); i++)
            prefixB[i] = prefixB[i-1] + (s[i] == 'b');
        
        for(int i=s.size()-2; i>=0; i--)
            suffixA[i] = suffixA[i+1] + (s[i] == 'a');

        for(int i=0; i<s.size(); i++) 
            ans = min(ans, suffixA[i] + prefixB[i] - 1);
        
        return ans;
    }
};