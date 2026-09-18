/*
    You are given a positive integer n. Let s be the binary representation of n without leading zeros. The reverse of a binary string s is obtained by writing the characters of
    s in the opposite order. You may flip any bit in s (change 0 → 1 or 1 → 0). Each flip affects exactly one bit. Return the minimum number of flips required to make s equal 
    to the reverse of its original form.

    Example 1:
    Input: n = 7
    Output: 0
    Explanation: The binary representation of 7 is "111". Its reverse is also "111", which is the same. Hence, no flips are needed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<string, string> revBin(int n) {
        string s = "";

        while(n) {
            int d = n % 2;
            n = n/2;

            s += to_string(d);
        }

        string rev = s;
        reverse(s.begin(), s.end());

        return {s, rev};
    }

    int minimumFlips(int n) {
        pair<string, string> str = revBin(n);

        string s = str.first;
        string r = str.second;

        int ans = 0;

        int i = 0;
        int j = 0;

        while(i < s.size()) {
            if(s[i] != r[j])
                ans++;
            i++;
            j++;
        }

        return ans;
    }
};