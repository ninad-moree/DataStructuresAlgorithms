/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order. A mapping of 
    digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string digit, string output, int index, vector<string>& ans, string mapp[]) {
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }

        int num = digit[index]-'0';
        string val = mapp[num];

        for(int i=0; i<val.length(); i++) {
            output.push_back(val[i]);
            solve(digit, output, index+1, ans, mapp);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string map1[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string output;
        int index=0;

        if(digits.length() == 0) 
            return ans;

        solve(digits, output, index, ans, map1);

        return ans;
    }
};