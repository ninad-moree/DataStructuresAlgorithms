/*
    Given a 0-indexed string s, repeatedly perform the following operation any number of times:
    Choose an index i in the string, and let c be the character in position i. Delete the closest occurrence of c to the left of i 
    (if any) and the closest occurrence of c to the right of i (if any).
    Your task is to minimize the length of s by performing the above operation any number of times.
    Return an integer denoting the length of the minimized string.

    Example 1:
    Input: s = "aaabc"
    Output: 3
    Explanation: In this example, s is "aaabc". We can start by selecting the character 'a' at index 1. We then remove the closest 'a' 
    to the left of index 1, which is at index 0, and the closest 'a' to the right of index 1, which is at index 2. After this operation, 
    the string becomes "abc". Any further operation we perform on the string will leave it unchanged. Therefore, the length of the minimized
    string is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> freq(26,0);

        for(auto i : s)
            freq[i - 'a']++;
        
        int ans = 0;
        
        for(int i=0; i<26; i++) {
            if(freq[i] != 0)
                ans++;
        }

        return ans;
    }
};