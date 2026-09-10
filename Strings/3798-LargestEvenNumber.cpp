/*
    You are given a string s consisting only of the characters '1' and '2'. You may delete any number of characters from s without changing the order of the remaining 
    characters. Return the largest possible resultant string that represents an even integer. If there is no such string, return the empty string "".

    Example 1:
    Input: s = "1112"
    Output: "1112"
    Explanation: The string already represents the largest possible even number, so no deletions are needed.
*/

#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    string largestEven(string s) {
        int i = s.size()-1;

        while(i >= 0) {
            if(s[i] == '2')
                break;
            
            i--;
        }

        if(i < 0)
            return "";

        string ans = "";

        for(int j=0; j<=i; j++) 
            ans += s[j];

        return ans;
    }
};