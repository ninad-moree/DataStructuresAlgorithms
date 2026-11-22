/*
    Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

    Example 1:
    Input: s = "aaabbb"
    Output: true
    Explanation: The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5. Hence, every 'a' appears before every 'b' and we return true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int firstB = -1;
        int lastA = -1;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'a')
                lastA = i;
            if(s[i] == 'b' && firstB == -1)
                firstB = i;
        }

        if(firstB == -1 || lastA == -1)
            return true;

        if(firstB > lastA)
            return true;
        return false;
    }
};