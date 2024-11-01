/*
    A fancy string is a string where no three consecutive characters are equal. Given a string s, delete the minimum possible number of characters
    from s to make it fancy. Return the final string after the deletion. It can be shown that the answer will always be unique.

    Example 1:
    Input: s = "leeetcode"
    Output: "leetcode"
    Explanation:
    Remove an 'e' from the first group of 'e's to create "leetcode".
    No three consecutive characters are equal, so return "leetcode".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string s2 = "";

        int i = 0;
        while(i <s.size()) {
            int j = i+1;
            int cnt = 1;
            
            while(s[j] == s[i]) {
                cnt++;
                j++;
            }

            if(cnt >= 3) {
                s2 += s[i];
                s2 += s[i];
            } else {
                for(int k=i; k<j; k++)
                    s2 += s[k];
            }

            i = j;
        }

        return s2;
    }
};