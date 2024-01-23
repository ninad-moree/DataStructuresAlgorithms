/*
    You are given an array of strings arr. A string s is formed by the concatenation of a subsequence 
    of arr that has unique characters.
    Return the maximum possible length of s.
    A subsequence is an array that can be derived from another array by deleting some or no elements 
    without changing the order of the remaining elements.

    Example 1:
    Input: arr = ["un","iq","ue"]
    Output: 4
    Explanation: All the valid concatenations are:
    - ""
    - "un"
    - "iq"
    - "ue"
    - "uniq" ("un" + "iq")
    - "ique" ("iq" + "ue")
    Maximum length is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backTrack(const vector<string>& arr, string current, int start, int& maxLength) {
        if (maxLength < current.length())
            maxLength = current.length();

        for (int i = start; i < arr.size(); i++) {
            if (!isValid(current, arr[i]))
                continue;

            backTrack(arr, current + arr[i], i + 1, maxLength);
        }
    }

    bool isValid(const string& currentString, const string& newString) {
        unordered_set<char> charSet;

        for (char ch : newString) {
            if (charSet.count(ch) > 0) 
                return false; 
                
            charSet.insert(ch);

            if (currentString.find(ch) != string::npos) 
                return false;  
        }

        return true;
    }

    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        backTrack(arr, "", 0, maxLength);
        return maxLength;
    }
};