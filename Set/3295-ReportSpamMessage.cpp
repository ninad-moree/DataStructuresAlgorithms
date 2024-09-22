/*
    You are given an array of strings message and an array of strings bannedWords.An array of words is considered spam if there are at least two 
    words in it that exactly match any word in bannedWords. Return true if the array message is spam, and false otherwise.

    Example 1:
    Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]
    Output: true
    Explanation:
    The words "hello" and "world" from the message array both appear in the bannedWords array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> s;
        for(auto i : bannedWords)
            s.insert(i);

        int cnt = 0;

        for(auto i : message) {
            if(s.find(i) != s.end())
                cnt++;
        }

        return cnt >= 2 ? true : false;
    }
};