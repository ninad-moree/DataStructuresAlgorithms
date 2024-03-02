/*
    Given three strings a, b, and c, your task is to find a string that has the minimum length and contains all three strings as substrings.
    If there are multiple such strings, return the lexicographically smallest one.
    Return a string denoting the answer to the problem.
    Notes
    A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has 
    a letter that appears earlier in the alphabet than the corresponding letter in b.
    A substring is a contiguous sequence of characters within a string.

    Example 1:
    Input: a = "abc", b = "bca", c = "aaa"
    Output: "aaabca"
    Explanation:  We show that "aaabca" contains all the given strings: a = ans[2...4], b = ans[3..5], c = ans[0..2]. It can be shown that 
    the length of the resulting string would be at least 6 and "aaabca" is the lexicographically smallest one.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string concatenate(string& a, string& b) {
        if(a.find(b) != string::npos) 
            return a;
        
        for(int i=min(a.size(), b.size()); i>=0; i--) {
            if(a.substr(a.size()-i) == b.substr(0,i))
                return a + b.substr(i);
        }

        return a + b;
    }

    string minimumString(string a, string b, string c) {
        vector<string> words(3);
        words[0] = a;
        words[1] = b;
        words[2] = c;

        string ans = "";

        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words.size(); j++) {
                for(int k=0; k<words.size(); k++) {
                    if(i!=j && j!=k && k!=i) {
                        string s1 = concatenate(words[i], words[j]);
                        string s2 = concatenate(s1, words[k]);
                        if(ans == "" || s2.size() < ans.size() || (s2.size() == ans.size() && s2.compare(ans) < 0))
                            ans = s2;
                    }
                }
            }
        }

        return ans;
    }
};
