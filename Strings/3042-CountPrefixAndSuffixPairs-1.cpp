/*
    You are given a 0-indexed string array words.
    Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2: isPrefixAndSuffix(str1, str2) 
    returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
    For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but 
    isPrefixAndSuffix("abc", "abcd") is false.
    Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

    Example 1:
    Input: words = ["a","aba","ababa","aa"]
    Output: 4
    Explanation: In this example, the counted index pairs are:
    i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
    i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
    i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
    i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
    Therefore, the answer is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m)
            return false;
        
        string x = s2.substr(0,n);
        string y = s2.substr(m-n);

        return s1==x && s1==y;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;

        for(int i=0; i<words.size()-1;i++) {
            for(int j=i+1; j<words.size();j++) {
                if(isPrefixAndSuffix(words[i], words[j]))
                    ans++;
            }
        }

        return ans;
    }
};