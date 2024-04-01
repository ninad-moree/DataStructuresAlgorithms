/*
    Given a string s consisting of words and spaces, return the length of the last word in the string.
    A word is a maximal substring consisting of non-space characters only.

    Example 1:
    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        int i = n-1;

        while(i>=0 && s[i]==' ') 
            i--;

        while(i>=0 && s[i]!= ' '){
            cnt++;
            i--;
        }
        
        return cnt;
    }
};