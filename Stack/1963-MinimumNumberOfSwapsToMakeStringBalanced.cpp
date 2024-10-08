/*
    You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
    A string is called balanced if and only if:
        It is the empty string, or
        It can be written as AB, where both A and B are balanced strings, or
        It can be written as [C], where C is a balanced string.
    You may swap the brackets at any two indices any number of times.

    Return the minimum number of swaps to make s balanced.

    Input: s = "]]][[["
    Output: 2
    Explanation: You can do the following to make the string balanced:
        - Swap index 0 with index 4. s = "[]][][".
        - Swap index 1 with index 5. s = "[[][]]".
        The resulting string is "[[][]]".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int openCount = 0;
        int closeCount = 0;
        
        for (char ch : s) {
            if (ch == '[')
                openCount++;
            else if (openCount > 0) 
                openCount--;
            else 
                closeCount++;
        }

        return (closeCount + 1) / 2;
    }
};