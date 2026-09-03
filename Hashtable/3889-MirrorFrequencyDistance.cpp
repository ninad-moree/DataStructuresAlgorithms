/*
    You are given a string s consisting of lowercase English letters and digits. For each character, its mirror character is defined by reversing the order of its character set:
    For letters, the mirror of a character is the letter at the same position from the end of the alphabet. For example, the mirror of 'a' is 'z', and the mirror of 'b' is 'y',
    and so on. For digits, the mirror of a character is the digit at the same position from the end of the range '0' to '9'. For example, the mirror of '0' is '9', and the 
    mirror of '1' is '8', and so on. For each unique character c in the string: Let m be its mirror character. Let freq(x) denote the number of times character x appears in the
    string. Compute the absolute difference between their frequencies, defined as: |freq(c) - freq(m)| The mirror pairs (c, m) and (m, c) are the same and must be counted only
    once. Return an integer denoting the total sum of these values over all such distinct mirror pairs.

    Example 1:
    Input: s = "ab1z9"
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> f1(10), f2(26);

        for (char &ch: s) {
            if (ch >= '0' && ch <= '9') 
                f1[ch-'0']++;
            else 
                f2[ch-'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 5; i++) 
            ans += abs(f1[i] - f1[9 - i]);

        for (int i = 0; i < 13; i++) 
            ans += abs(f2[i] - f2[25 - i]);

        return ans;
    }
};