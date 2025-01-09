/*
    You are given an array of strings words and a string pref. Return the number of strings in words that contain pref as a prefix. A prefix of a
    string s is any leading contiguous substring of s.

    Example 1:
    Input: words = ["pay","attention","practice","attend"], pref = "at"
    Output: 2
    Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int len = pref.size();

        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            if(word.substr(0, len) == pref)
                cnt++;
        }

        return cnt;
    }
};