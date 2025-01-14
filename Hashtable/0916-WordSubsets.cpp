/*
    You are given two string arrays words1 and words2. A string b is a subset of string a if every letter in b occurs in a including multiplicity.
    For example, "wrr" is a subset of "warrior" but is not a subset of "world". A string a from words1 is universal if for every string b in words2, 
    b is a subset of a. Return an array of all the universal strings in words1. You may return the answer in any order.

    Example 1:
    Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
    Output: ["facebook","google","leetcode"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubset(vector<int> freq1, vector<int> freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq2[i] > freq1[i]) {
                return false;
            }
        }
        return true;
    }


    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        
        for (const string& b : words2) {
            vector<int> freq(26, 0);
            for (char ch : b) 
                freq[ch - 'a']++;
            
            for (int i = 0; i < 26; i++) 
                maxFreq[i] = max(maxFreq[i], freq[i]);
        }

        vector<string> ans;
        for (const string& a : words1) {
            vector<int> freq(26, 0);
            for (char ch : a) 
                freq[ch - 'a']++;
            
            if (isSubset(freq, maxFreq)) 
                ans.push_back(a);
        }

        return ans;
    }
};