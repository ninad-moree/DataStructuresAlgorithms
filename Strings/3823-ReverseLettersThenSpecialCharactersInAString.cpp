/*
    You are given a string s consisting of lowercase English letters and special characters. Your task is to perform these in order: Reverse the lowercase letters and place 
    them back into the positions originally occupied by letters. Reverse the special characters and place them back into the positions originally occupied by special characters.
    Return the resulting string after performing the reversals.

    Example 1:
    Input: s = ")ebc#da@f("
    Output: "(fad@cb#e)"
    Explanation: The letters in the string are ['e', 'b', 'c', 'd', 'a', 'f']: Reversing them gives ['f', 'a', 'd', 'c', 'b', 'e'], s becomes ")fad#cb@e("
    ​​​​​​​The special characters in the string are [')', '#', '@', '(']: Reversing them gives ['(', '@', '#', ')'], s becomes "(fad@cb#e)"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();

        int i = 0;
        int j = n-1;

        while(i < j) {
            while(i < j && !(s[i] >= 'a' && s[i] <= 'z'))
                i++;
            
            while(i < j && !(s[j] >= 'a' && s[j] <= 'z'))
                j--;

            if(i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        i = 0;
        j = n-1;

        while(i < j) {
            while(i < j && (s[i] >= 'a' && s[i] <= 'z'))
                i++;
            
            while(i < j && (s[j] >= 'a' && s[j] <= 'z'))
                j--;

            if(i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};