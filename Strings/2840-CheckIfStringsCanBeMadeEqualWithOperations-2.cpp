/*
    You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
    You can apply the following operation on any of the two strings any number of times:
    Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.

    Example 1:
    Input: s1 = "abcdba", s2 = "cabdab"
    Output: true
    Explanation: We can apply the following operations on s1:
    - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
    - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
    - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1 == s2)
            return true;

        int n = s1.size();

        vector<char> even1, even2;
        for (int i = 0; i < n; i += 2) {
            even1.push_back(s1[i]);
            even2.push_back(s2[i]);
        }

        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());

        if (even1 != even2)
            return false;

        vector<char> odd1, odd2;
        for (int i = 1; i < n; i += 2) {
            odd1.push_back(s1[i]);
            odd2.push_back(s2[i]);
        }

        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        if (odd1 != odd2)
            return false;

        return true;
    }
};