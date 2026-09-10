/*
    You are given a string s consisting only of lowercase English letters. A prefix of s is called a residue if the number of distinct characters in the prefix is equal to 
    len(prefix) % 3. Return the count of residue prefixes in s. A prefix of a string is a non-empty substring that starts from the beginning of the string and extends to any 
    point within it.

    Example 1:
    Input: s = "abc"
    Output: 2
    Explanation:​​​​​​​ Prefix "a" has 1 distinct character and length modulo 3 is 1, so it is a residue. Prefix "ab" has 2 distinct characters and length modulo 3 is 2, so it is a 
    residue. Prefix "abc" does not satisfy the condition. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> freq(26);
        int ans = 0;
        int cnt = 0;

        for(int i=0; i<s.size(); i++) {
            if(freq[s[i] - 'a'] == 0)
                cnt++;
            freq[s[i] - 'a']++;
            
            if(cnt == (i+1) % 3)
                ans++;
        }

        return ans;
    }
};