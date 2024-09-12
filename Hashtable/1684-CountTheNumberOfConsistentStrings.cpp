/*
    You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the 
    string appear in the string allowed. Return the number of consistent strings in the array words.

    Example 1:
    Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
    Output: 2
    Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto i : allowed)
            mp[i]++;

        int ans = 0;

        for(auto i : words) {
            string w = i;
            bool isAllowed = true;
            for(auto j : w) {
                if(mp.find(j) == mp.end()) {
                    isAllowed = false;
                    break;
                }
            }
            if(isAllowed)
                ans++;
        }

        return ans;
    }
};