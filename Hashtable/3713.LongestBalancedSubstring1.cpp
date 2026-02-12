/*
    You are given a string s consisting of lowercase English letters. A substring of s is called balanced if all distinct characters in the substring appear the same number of 
    times. Return the length of the longest balanced substring of s.

    Example 1:
    Input: s = "abbac"
    Output: 4
    Explanation: The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOccurence(string& s, unordered_map<char, int>& mp) {
        int freq = mp[s[0]];
        for(auto i : mp) {
            if(i.second != freq)
                return false;
        }

        return true;
    }

    int longestBalanced(string s) {
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            string str = "";
            unordered_map<char, int> mp;

            for(int j=i; j<s.size(); j++) {
                str += s[j];
                mp[s[j]]++;

                if(checkOccurence(str, mp)) 
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};