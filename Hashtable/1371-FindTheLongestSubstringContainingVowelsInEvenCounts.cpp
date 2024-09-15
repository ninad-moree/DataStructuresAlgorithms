/*
    Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' 
    must appear an even number of times.

    Example 1:
    Input: s = "eleetminicoworoep"
    Output: 13
    Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int cnta = 0, cnte = 0, cnti = 0, cnto = 0, cntu = 0;
        int len = 0;
        unordered_map<string, int> mp;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a') 
                cnta++;
            if(s[i] == 'e') 
                cnte++;
            if(s[i] == 'i') 
                cnti++;
            if(s[i] == 'o') 
                cnto++;
            if(s[i] == 'u') 
                cntu++;

            string even = to_string(cnta%2) + to_string(cnte%2) + to_string(cnti%2) +to_string(cnto%2) + to_string(cntu%2);
            if(even == "00000") 
                len = i + 1;
            else {
                if(!mp.count(even)) 
                    mp[even] = i;
                len = max(len, i - mp[even]);
            }
        }

        return len;
    }
};