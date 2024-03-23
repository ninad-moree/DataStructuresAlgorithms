/*
    Given a string s, find any substring of length 2 which is also present in the reverse of s.
    Return true if such a substring exists, and false otherwise.

    Example 1:
    Input: s = "leetcode"
    Output: true
    Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringToVec(string s) {
        vector<string> words(s.size() - 1);
        for(int i=0; i<s.size()-1; i++) {
            string w = "";
            w += s[i];
            w += s[i+1];

            words[i] = w;
        }

        return words;
    }
    bool isSubstringPresent(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<string> w1 = stringToVec(s);
        vector<string> w2 = stringToVec(s2);

        unordered_map<string, char> mp;

        for(int i=0; i<w1.size(); i++) {
            for(int j=0; j<w1.size(); j++) {
                if(w2[i] == w1[j]) 
                    return true;
            }
        }

        return false;
    }
};