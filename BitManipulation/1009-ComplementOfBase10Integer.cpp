/*
    The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation. For example, The integer 5 is 
    "101" in binary and its complement is "010" which is the integer 2. Given an integer n, return its complement.

    Example 1:
    Input: n = 5
    Output: 2
    Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
*/

#include<bits/stdc++.h>
using namespace std;  

class Solution {
public:
    string toBinary(int n) {
        string ans = "";

        while(n > 0) {
            int rem = n % 2;
            ans += to_string(rem);
             n = n/2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int toDecimal(string n) {
        int ans = 0;

        for(int i = 0; i < n.size(); i++) 
            ans = ans * 2 + (n[i] - '0');

        return ans;
    }

    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        string nBinary = toBinary(n);

        string complement = "";
        for(auto i : nBinary) {
            if(i == '0') 
                complement += '1';
            else
                complement += '0';
        }

        int ans = toDecimal(complement);

        return ans;
    }
};