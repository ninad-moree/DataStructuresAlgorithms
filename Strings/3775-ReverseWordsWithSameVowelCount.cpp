/*
    You are given a string s consisting of lowercase English words, each separated by a single space. Determine how many vowels appear in the first word. Then, reverse each 
    following word that has the same vowel count. Leave all remaining words unchanged. Return the resulting string. Vowels are 'a', 'e', 'i', 'o', and 'u'.

    Example 1:
    Input: s = "cat and mice"
    Output: "cat dna mice"
    Explanation:​​​​​​​ The first word "cat" has 1 vowel. "and" has 1 vowel, so it is reversed to form "dna". "mice" has 2 vowels, so it remains unchanged. Thus, the resulting string
    is "cat dna mice".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int vowelCnt = 0;
        string w = "";
        int i = 0;

        vector<string> words;

        while(i < s.size()) {
            if(s[i] == ' ') {
                i++;
                words.push_back(w);
                w = "";
                continue;
            }

            w += s[i];
            i++;
        }

        words.push_back(w);

        for(auto j : words[0]) {
            if(j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
                vowelCnt++;
        }

        string ans = "";
        ans += words[0];

        for(int j=1; j<words.size(); j++) {
            string w = words[j];
            int cnt = 0;

            for(auto k : w) {
                if(k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u')
                    cnt++;
            }

            if(cnt == vowelCnt) {
                reverse(w.begin(), w.end());
                ans += " ";
                ans += w;
            } else {
                ans += " ";
                ans += w;
            }
        }

        return ans;
    }
};