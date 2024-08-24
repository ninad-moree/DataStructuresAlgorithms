/*
    Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in s will be 
    separated by at least one space. Return a string of the words in reverse order concatenated by a single space.
    Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space 
    separating the words. Do not include any extra spaces.

    Example 1:
    Input: s = "the sky is blue"
    Output: "blue is sky the"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string token;

        vector<string> res;
        while(iss >> token)
            res.push_back(token);

        reverse(res.begin(), res.end());

        string ans = "";
        for(int i=0; i<res.size(); i++) {
            if(i != res.size()-1) {
                ans += res[i];
                ans += " ";
            }
            else
                ans += res[i];
        }

        return ans;
    }
};