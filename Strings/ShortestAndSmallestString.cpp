/*
    You are given a binary string s and a positive integer k. A substring of s is beautiful if the number of 1's in it is exactly k.
    Let len be the length of the shortest beautiful substring. Return the lexicographically smallest beautiful substring of string s 
    with length equal to len. If s doesn't contain a  beautiful substring, return an empty string.
    A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, 
    a has a character strictly larger than the corresponding character in b.
    For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, 
    and d is greater than c.
    
    Example 1:
    Input: s = "100011001", k = 3
    Output: "11001"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        vector<string> strings;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            string current;
            int count1 = 0;

            for (int j = i; j < n; ++j) {
                current += s[j];
                if (s[j] == '1') 
                    count1++;

                if (count1 == k ) {
                    strings.push_back(current);
                    break;
                }
            }
        }

        sort(strings.begin(), strings.end());

        if(strings.empty())
            return "";

        ans = strings[0];
        int len = ans.size();

        for (const auto& str : strings) {
            if(str.size() < len) {
                ans = str;
                len = str.size();
            }
        }

        return ans;
    }
};
