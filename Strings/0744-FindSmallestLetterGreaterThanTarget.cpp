/*
    You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different 
    characters in letters. Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, 
    return the first character in letters.

    Example 1:
    Input: letters = ["c","f","j"], target = "a"
    Output: "c"
    Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char c = '0';

        for(auto i : letters) {
            if(i > target) {
                c = i;
                break;
            }
        }

        if(c == '0')
            return letters[0];
        return c;
    }
};