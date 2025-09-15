/*
    There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly. Given a string text of words 
    separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number
    of words in text you can fully type using this keyboard.

    Example 1:
    Input: text = "hello world", brokenLetters = "ad"
    Output: 1
    Explanation: We cannot type "world" because the 'd' key is broken.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words;

        stringstream ss(text);
        string token;

        while(ss >> token) 
            words.push_back(token);

        unordered_set<char> st;
        int cnt = 0;

        for(auto& it : brokenLetters)
            st.insert(it);

        for(auto w: words) {
            for(char c : w) {
                if(st.find(c) != st.end()) {
                    cnt++;
                    break;
                }
            }
        }

        return words.size() - cnt;
    }
};