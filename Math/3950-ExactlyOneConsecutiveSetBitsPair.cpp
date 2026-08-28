/*
    You are given an integer n. Return true if its binary representation contains exactly one adjacent pair of set bits, and false otherwise.

    Example 1:
    Input: n = 6
    Output: true
    Explanation: Binary representation of 6 is 110. There is exactly one adjacent pair of set bits ("11"). Thus, the answer is true​​​​​​​.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        string str = "";

        while(n) {
            int rem = n % 2;
            n = n/2;

            str += to_string(rem);
        }

        reverse(str.begin(), str.end());
        
        int cnt = 0;

        for(int i=1; i<str.size(); i++) {
            if(str[i-1] == '1' && str[i] == '1')
                cnt++;
        }

        return cnt == 1;
    }
};