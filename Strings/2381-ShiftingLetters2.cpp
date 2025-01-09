/*
    You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, 
    shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if 
    directioni = 0. Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
    Return the final string after all such shifts to s are applied.

    Example 1:
    Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
    Output: "ace"
    Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
    Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
    Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> changes(n + 1, 0);

        for(int i=0; i<shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2] ? 1 : -1;

            changes[start] += dir;
            changes[end+1] -= dir;
        }

        vector<int> totalChange(n, 0);
        int total = 0;
        for(int i=0; i<n; i++) {
            total += changes[i];
            totalChange[i] = total;
        }

        for(int i=0; i<n; i++) {
            int shift = (s[i] - 'a' + totalChange[i]) % 26;
            if(shift < 0)
                shift += 26;

            s[i] = 'a' + shift;
        }

        return s;
    }
};