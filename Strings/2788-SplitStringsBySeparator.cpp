/*
    Given an array of strings words and a character separator, split each string in words by separator.
    Return an array of strings containing the new strings formed after the splits, excluding empty strings.
    
    Example 1:
    Input: words = ["one.two.three","four.five","six"], separator = "."
    Output: ["one","two","three","four","five","six"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;

        for(int i=0; i<words.size(); i++) {
            string str = words[i];

            istringstream iss(str);
            string res;

            while(getline(iss, res, separator)) {
                if(res != "")
                    ans.push_back(res);
            }
        }

        return ans;
    }
};