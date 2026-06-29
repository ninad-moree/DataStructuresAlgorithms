/*
    Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word. A substring is a contiguous sequence of 
    characters within a string.

    Example 1:
    Input: patterns = ["a","abc","bc","d"], word = "abc"
    Output: 3
    Explanation: 
    - "a" appears as a substring in "abc". - "abc" appears as a substring in "abc". - "bc" appears as a substring in "abc". - "d" does not appear as a substring in "abc". 
    3 of the strings in patterns appear as a substring in word.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        unordered_map<string, int> mp;

        for(int i=0; i<word.size(); i++) {
            string res = "";
            for(int j=i; j<word.size(); j++) {
                res += word[j];
                mp[res]++;
            }
        }

        for(int i=0; i<patterns.size(); i++) {
            if(mp.find(patterns[i]) != mp.end())
                ans++;
        }

        return ans;

        // int ans = 0;

        // for(auto i : patterns) {
        //     if(word.find(i) != string::npos)
        //         ans++;
        // }

        // return ans;
    }
};