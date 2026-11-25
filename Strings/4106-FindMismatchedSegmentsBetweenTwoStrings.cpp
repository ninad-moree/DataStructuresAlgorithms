/*
    You are given two strings s1 and s2 of the same length. A mismatched segment is a maximal contiguous range of indices where the characters of s1 and s2 differ at every 
    index. Return a 2D array containing [sub1, sub2] for each mismatched segment, where sub1 and sub2 are the corresponding substrings from s1 and s2, respectively. Return the 
    segments in increasing order of their starting indices. If there are no mismatched segments, return an empty array.

    Example 1:
    Input: s1 = "earth", s2 = "empty"
    Output: [["ar","mp"],["h","y"]]
    Explanation: The characters at indices 1 & 2 differ, forming the mismatched segment ["ar","mp"]. The characters at index 4 differ, forming the mismatched segment ["h","y"].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;

        int i = 0;
        string r1 = "";
        string r2 = "";

        while(i < s1.size()) {
            char ch1 = s1[i];
            char ch2 = s2[i];

            if(ch1 == ch2) {
                i++;

                if(r1.size() > 0 && r2.size() > 0) 
                    ans.push_back({r1, r2});

                r1 = "";
                r2 = "";
            } else {
                r1 += ch1;
                r2 += ch2;

                i++;
            }
        }

        if(r1.size() > 0 && r2.size() > 0) 
            ans.push_back({r1, r2});

        return ans;
    }
};