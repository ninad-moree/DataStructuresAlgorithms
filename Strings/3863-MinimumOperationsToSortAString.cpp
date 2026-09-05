/*
    You are given a string s consisting of lowercase English letters. In one operation, you can select any substring of s that is not the entire string and sort it in non-
    descending alphabetical order. Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

    Example 1:
    Input: s = "dog"
    Output: 1
    Explanation:​​​​​​​ Sort substring "og" to "go". Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string t = s;
        sort(t.begin(), t.end());

        if(s == t)
            return 0;

        if(n == 2)
            return -1;

        string t1 = s;
        string t2 = s;

        sort(t1.begin() + 1, t1.end());
        sort(t2.begin(), t2.end() - 1);

        if(t == t1 || t == t2)
            return 1;

        char mini = s[0];
        char maxi = s[0];
        unordered_map<char, int> mp;

        for(auto ch : s) {
            mp[ch]++;
            mini = min(mini, ch);
            maxi = max(maxi, ch);
        }

        if(maxi == s[0] && mini == s[n-1] && mp[mini] == 1 && mp[maxi] == 1)
            return 3;
        return 2;
    }
};